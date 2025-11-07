#!/usr/bin/env python3
import re
from pathlib import Path

base_stats_path = Path(r"c:\Users\EBAfa\OneDrive\Desktop\base_stats_rr.c")
gen1_path = Path(r"c:\Users\EBAfa\DeCUMPs\pokeemerald-expansion-fr\src\data\pokemon\species_info\gen_1_families.h")

# fields of interest
# fields of interest
fields = ['baseHP','baseAttack','baseDefense','baseSpAttack','baseSpDefense','baseSpeed']
# also parse types
type_fields = ['type1', 'type2']

text = base_stats_path.read_text(encoding='utf-8')

# regex to extract species blocks from base_stats_rr.c
pattern = re.compile(r"\[SPECIES_([A-Z0-9_]+)\]\s*=\s*\{", re.M)

species_map = {}
for m in pattern.finditer(text):
    name = m.group(1)
    start = m.end()  # position after '{'
    # find matching closing brace for this block
    i = start
    depth = 1
    while i < len(text) and depth > 0:
        if text[i] == '{':
            depth += 1
        elif text[i] == '}':
            depth -= 1
        i += 1
    block = text[start:i-1]
    stats = {}
    for f in fields:
        r = re.search(r"\.%s\s*=\s*([0-9]+)" % re.escape(f), block)
        if r:
            stats[f] = r.group(1)
    # parse types (like .type1 = TYPE_GRASS,)
    for tf in type_fields:
        r = re.search(r"\.%s\s*=\s*([^,\n]+)" % re.escape(tf), block)
        if r:
            stats[tf] = r.group(1).strip()
    if stats:
        species_map[name] = stats

print(f"Parsed {len(species_map)} species with stats from base_stats_rr.c")

# Read gen1 file
gen1_text = gen1_path.read_text(encoding='utf-8')
orig_text = gen1_text

# For each species found, locate its block in gen1_text and replace stat assignments
for name, stats in species_map.items():
    # find the species occurrence
    m = re.search(r"\[SPECIES_%s\]\s*=\s*\{" % re.escape(name), gen1_text)
    if not m:
        continue
    start = m.end()
    i = start
    depth = 1
    while i < len(gen1_text) and depth > 0:
        if gen1_text[i] == '{':
            depth += 1
        elif gen1_text[i] == '}':
            depth -= 1
        i += 1
    block = gen1_text[start:i-1]
    new_block = block
    changed = [False]
    for f in fields:
        if f in stats:
            # replace the assignment for this field inside new_block
            # match lines like: .baseHP        = 45,  (allow arbitrary spacing and expressions)
            p = re.compile(r"(\.%s\s*=\s*)([^,\n]+)(,)" % re.escape(f))
            def repl(m2):
                old = m2.group(2)
                new = stats[f]
                if old.strip() != new:
                    changed[0] = True
                    return m2.group(1) + new + m2.group(3)
                return m2.group(0)
            new_block, nsub = p.subn(repl, new_block)
    # Also update types if available
    if 'type1' in stats:
        t1 = stats.get('type1')
        t2 = stats.get('type2')
        # build replacement MON_TYPES(...) string
        # normalize and deduplicate types: prefer a single type if identical or if type2 is TYPE_NONE/missing
        t1_norm = t1.strip() if t1 else ''
        t2_norm = t2.strip() if t2 else ''
        if not t2_norm or t2_norm == 'TYPE_NONE' or t2_norm == t1_norm:
            types_args = f"{t1_norm}"
        else:
            types_args = f"{t1_norm}, {t2_norm}"
        # replace the .types = MON_TYPES(...) occurrence robustly (handle nested parentheses)
        n_types = 0
        types_pos = new_block.find('.types')
        if types_pos != -1:
            mon_pos = new_block.find('MON_TYPES', types_pos)
            if mon_pos != -1:
                paren_start = new_block.find('(', mon_pos)
                if paren_start != -1:
                    # scan to matching closing paren
                    j = paren_start + 1
                    depth = 1
                    while j < len(new_block) and depth > 0:
                        if new_block[j] == '(':
                            depth += 1
                        elif new_block[j] == ')':
                            depth -= 1
                        j += 1
                    if depth == 0:
                        paren_end = j - 1
                        # replace inner args between paren_start+1 and paren_end
                        new_block = new_block[:paren_start+1] + types_args + new_block[paren_end:]
                        n_types = 1

    if changed[0] or ('type1' in stats and n_types > 0):
        gen1_text = gen1_text[:start] + new_block + gen1_text[i-1:]

# If changes were made, backup and write
if gen1_text != orig_text:
    bak = gen1_path.with_suffix('.h.bak')
    bak.write_text(orig_text, encoding='utf-8')
    gen1_path.write_text(gen1_text, encoding='utf-8')
    print(f"Updated {gen1_path} and wrote backup to {bak}")
else:
    print("No changes needed; gen1 file already matches base_stats_rr.c for specified fields.")
