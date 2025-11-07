#!/usr/bin/env python3
import re
from pathlib import Path

base_stats_path = Path(r"c:\Users\EBAfa\OneDrive\Desktop\base_stats_rr.c")
gen1_path = Path(r"c:\Users\EBAfa\DeCUMPs\pokeemerald-expansion-fr\src\data\pokemon\species_info\gen_1_families.h")

# fields of interest
fields = ['baseHP','baseAttack','baseDefense','baseSpAttack','baseSpDefense','baseSpeed']

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
    if changed[0]:
        gen1_text = gen1_text[:start] + new_block + gen1_text[i-1:]

# If changes were made, backup and write
if gen1_text != orig_text:
    bak = gen1_path.with_suffix('.h.bak')
    bak.write_text(orig_text, encoding='utf-8')
    gen1_path.write_text(gen1_text, encoding='utf-8')
    print(f"Updated {gen1_path} and wrote backup to {bak}")
else:
    print("No changes needed; gen1 file already matches base_stats_rr.c for specified fields.")
