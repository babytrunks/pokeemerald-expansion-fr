#!/usr/bin/env python3
import re
from pathlib import Path

base_stats_path = Path(r"c:\Users\EBAfa\OneDrive\Desktop\GBA\RadicalRed\Dynamic-Pokemon-Expansion\src\Base_Stats.c")
gen1_path = Path(r"c:\Users\EBAfa\DeCUMPs\pokeemerald-expansion-fr\src\data\pokemon\species_info\gen_1_families.h")

# fields of interest
# fields of interest
fields = ['baseHP','baseAttack','baseDefense','baseSpAttack','baseSpDefense','baseSpeed']
# also parse types
type_fields = ['type1', 'type2']
# ability fields to parse from base_stats_rr.c
ability_fields = ['ability1', 'ability2', 'hiddenAbility']

# --- Ability normalization ---
# Editable override map for abilities that can't be auto-mapped.
# Keys should be the raw token found in base_stats_rr.c and values the
# canonical token from include/constants/abilities.h you want to use.
# Example: { 'ABILITY_SOLARPOWER': 'ABILITY_SOLAR_POWER' }
ability_override_map = {
    'ABILITY_SPEEDBOOST': 'ABILITY_SPEED_BOOST',
    'ABILITY_BATTLEARMOR': 'ABILITY_BATTLE_ARMOR',
    'ABILITY_SANDVEIL': 'ABILITY_SAND_VEIL',
    'ABILITY_VOLTABSORB': 'ABILITY_VOLT_ABSORB',
    'ABILITY_WATERABSORB': 'ABILITY_WATER_ABSORB',
    'ABILITY_CLOUDNINE': 'ABILITY_CLOUD_NINE',
    'ABILITY_COMPOUNDEYES': 'ABILITY_COMPOUND_EYES',
    'ABILITY_COLORCHANGE': 'ABILITY_COLOR_CHANGE',
    'ABILITY_FLASHFIRE': 'ABILITY_FLASH_FIRE',
    'ABILITY_SHIELDDUST': 'ABILITY_SHIELD_DUST',
    'ABILITY_OWNTEMPO': 'ABILITY_OWN_TEMPO',
    'ABILITY_SUCTIONCUPS': 'ABILITY_SUCTION_CUPS',
    'ABILITY_SHADOWTAG': 'ABILITY_SHADOW_TAG',
    'ABILITY_WONDERGUARD': 'ABILITY_WONDER_GUARD',
    'ABILITY_EFFECTSPORE': 'ABILITY_EFFECT_SPORE',
    'ABILITY_CLEARBODY': 'ABILITY_CLEAR_BODY',
    'ABILITY_NATURALCURE': 'ABILITY_NATURAL_CURE',
    'ABILITY_LIGHTNINGROD': 'ABILITY_LIGHTNING_ROD',
    'ABILITY_SERENEGRACE': 'ABILITY_SERENE_GRACE',
    'ABILITY_SWIFTSWIM': 'ABILITY_SWIFT_SWIM',
    'ABILITY_HUGEPOWER': 'ABILITY_HUGE_POWER',
    'ABILITY_POISONPOINT': 'ABILITY_POISON_POINT',
    'ABILITY_INNERFOCUS': 'ABILITY_INNER_FOCUS',
    'ABILITY_MAGMAARMOR': 'ABILITY_MAGMA_ARMOR',
    'ABILITY_WATERVEIL': 'ABILITY_WATER_VEIL',
    'ABILITY_MAGNETPULL': 'ABILITY_MAGNET_PULL',
    'ABILITY_RAINDISH': 'ABILITY_RAIN_DISH',
    'ABILITY_SANDSTREAM': 'ABILITY_SAND_STREAM',
    'ABILITY_THICKFAT': 'ABILITY_THICK_FAT',
    'ABILITY_EARLYBIRD': 'ABILITY_EARLY_BIRD',
    'ABILITY_FLAMEBODY': 'ABILITY_FLAME_BODY',
    'ABILITY_RUNAWAY': 'ABILITY_RUN_AWAY',
    'ABILITY_KEENEYE': 'ABILITY_KEEN_EYE',
    'ABILITY_HYPERCUTTER': 'ABILITY_HYPER_CUTTER',
    'ABILITY_CUTECHARM': 'ABILITY_CUTE_CHARM',
    'ABILITY_STICKYHOLD': 'ABILITY_STICKY_HOLD',
    'ABILITY_SHEDSKIN': 'ABILITY_SHED_SKIN',
    'ABILITY_MARVELSCALE': 'ABILITY_MARVEL_SCALE',
    'ABILITY_LIQUIDOOZE': 'ABILITY_LIQUID_OOZE',
    'ABILITY_ROCKHEAD': 'ABILITY_ROCK_HEAD',
    'ABILITY_ARENATRAP': 'ABILITY_ARENA_TRAP',
    'ABILITY_VITALSPIRIT': 'ABILITY_VITAL_SPIRIT',
    'ABILITY_WHITESMOKE': 'ABILITY_WHITE_SMOKE',
    'ABILITY_PUREPOWER': 'ABILITY_PURE_POWER',
    'ABILITY_SHELLARMOR': 'ABILITY_SHELL_ARMOR',
    'ABILITY_AIRLOCK': 'ABILITY_AIR_LOCK',
    'ABILITY_TANGLEDFEET': 'ABILITY_TANGLED_FEET',
    'ABILITY_MOTORDRIVE': 'ABILITY_MOTOR_DRIVE',
    'ABILITY_SNOWCLOAK': 'ABILITY_SNOW_CLOAK',
    'ABILITY_ANGERPOINT': 'ABILITY_ANGER_POINT',
    'ABILITY_DRYSKIN': 'ABILITY_DRY_SKIN',
    'ABILITY_IRONFIST': 'ABILITY_IRON_FIST',
    'ABILITY_POISONHEAL': 'ABILITY_POISON_HEAL',
    'ABILITY_SKILLLINK': 'ABILITY_SKILL_LINK',
    'ABILITY_SOLARPOWER': 'ABILITY_SOLAR_POWER',
    'ABILITY_QUICKFEET': 'ABILITY_QUICK_FEET',
    'ABILITY_MAGICGUARD': 'ABILITY_MAGIC_GUARD',
    'ABILITY_NOGUARD': 'ABILITY_NO_GUARD',
    'ABILITY_SLOWSTART': 'ABILITY_SLOW_START',
    'ABILITY_STORMDRAIN': 'ABILITY_STORM_DRAIN',
    'ABILITY_ICEBODY': 'ABILITY_ICE_BODY',
    'ABILITY_SOLIDROCK': 'ABILITY_SOLID_ROCK',
    'ABILITY_SNOWWARNING': 'ABILITY_SNOW_WARNING',
    'ABILITY_HONEYGATHER': 'ABILITY_HONEY_GATHER',
    'ABILITY_FLOWERGIFT': 'ABILITY_FLOWER_GIFT',
    'ABILITY_BADDREAMS': 'ABILITY_BAD_DREAMS',
    'ABILITY_SHEERFORCE': 'ABILITY_SHEER_FORCE',
    'ABILITY_CURSEDBODY': 'ABILITY_CURSED_BODY',
    'ABILITY_FRIENDGUARD': 'ABILITY_FRIEND_GUARD',
    'ABILITY_WEAKARMOR': 'ABILITY_WEAK_ARMOR',
    'ABILITY_HEAVYMETAL': 'ABILITY_HEAVY_METAL',
    'ABILITY_LIGHTMETAL': 'ABILITY_LIGHT_METAL',
    'ABILITY_TOXICBOOST': 'ABILITY_TOXIC_BOOST',
    'ABILITY_FLAREBOOST': 'ABILITY_FLARE_BOOST',
    'ABILITY_POISONTOUCH': 'ABILITY_POISON_TOUCH',
    'ABILITY_BIGPECKS': 'ABILITY_BIG_PECKS',
    'ABILITY_SANDRUSH': 'ABILITY_SAND_RUSH',
    'ABILITY_WONDERSKIN': 'ABILITY_WONDER_SKIN',
    'ABILITY_MAGICBOUNCE': 'ABILITY_MAGIC_BOUNCE',
    'ABILITY_SAPSIPPER': 'ABILITY_SAP_SIPPER',
    'ABILITY_SANDFORCE': 'ABILITY_SAND_FORCE',
    'ABILITY_IRONBARBS': 'ABILITY_IRON_BARBS',
    'ABILITY_ZENMODE': 'ABILITY_ZEN_MODE',
    'ABILITY_VICTORYSTAR': 'ABILITY_VICTORY_STAR',
    'ABILITY_AROMAVEIL': 'ABILITY_AROMA_VEIL',
    'ABILITY_FLOWERVEIL': 'ABILITY_FLOWER_VEIL',
    'ABILITY_CHEEKPOUCH': 'ABILITY_CHEEK_POUCH',
    'ABILITY_FURCOAT': 'ABILITY_FUR_COAT',
    'ABILITY_STRONGJAW': 'ABILITY_STRONG_JAW',
    'ABILITY_SWEETVEIL': 'ABILITY_SWEET_VEIL',
    'ABILITY_STANCECHANGE': 'ABILITY_STANCE_CHANGE',
    'ABILITY_GALEWINGS': 'ABILITY_GALE_WINGS',
    'ABILITY_MEGALAUNCHER': 'ABILITY_MEGA_LAUNCHER',
    'ABILITY_GRASSPELT': 'ABILITY_GRASS_PELT',
    'ABILITY_TOUGHCLAWS': 'ABILITY_TOUGH_CLAWS',
    'ABILITY_PARENTALBOND': 'ABILITY_PARENTAL_BOND',
    'ABILITY_DARKAURA': 'ABILITY_DARK_AURA',
    'ABILITY_FAIRYAURA': 'ABILITY_FAIRY_AURA',
    'ABILITY_AURABREAK': 'ABILITY_AURA_BREAK',
    'ABILITY_PRIMORDIALSEA': 'ABILITY_PRIMORDIAL_SEA',
    'ABILITY_DESOLATELAND': 'ABILITY_DESOLATE_LAND',
    'ABILITY_DELTASTREAM': 'ABILITY_DELTA_STREAM',
    'ABILITY_WIMPOUT': 'ABILITY_WIMP_OUT',
    'ABILITY_EMERGENCYEXIT': 'ABILITY_EMERGENCY_EXIT',
    'ABILITY_WATERCOMPACTION': 'ABILITY_WATER_COMPACTION',
    'ABILITY_SHIELDSDOWN': 'ABILITY_SHIELDS_DOWN',
    'ABILITY_SLUSHRUSH': 'ABILITY_SLUSH_RUSH',
    'ABILITY_LONGREACH': 'ABILITY_LONG_REACH',
    'ABILITY_LIQUIDVOICE': 'ABILITY_LIQUID_VOICE',
    'ABILITY_SURGESURFER': 'ABILITY_SURGE_SURFER',
    'ABILITY_BATTLEBOND': 'ABILITY_BATTLE_BOND',
    'ABILITY_POWERCONSTRUCT': 'ABILITY_POWER_CONSTRUCT',
    'ABILITY_QUEENLYMAJESTY': 'ABILITY_QUEENLY_MAJESTY',
    'ABILITY_INNARDSOUT': 'ABILITY_INNARDS_OUT',
    'ABILITY_SOULHEART': 'ABILITY_SOUL_HEART',
    'ABILITY_TANGLINGHAIR': 'ABILITY_TANGLING_HAIR',
    'ABILITY_POWEROFALCHEMY': 'ABILITY_POWER_OF_ALCHEMY',
    'ABILITY_BEASTBOOST': 'ABILITY_BEAST_BOOST',
    'ABILITY_RKSSYSTEM': 'ABILITY_RKS_SYSTEM',
    'ABILITY_ELECTRICSURGE': 'ABILITY_ELECTRIC_SURGE',
    'ABILITY_PSYCHICSURGE': 'ABILITY_PSYCHIC_SURGE',
    'ABILITY_MISTYSURGE': 'ABILITY_MISTY_SURGE',
    'ABILITY_GRASSYSURGE': 'ABILITY_GRASSY_SURGE',
    'ABILITY_FULLMETALBODY': 'ABILITY_FULL_METAL_BODY',
    'ABILITY_SHADOWSHIELD': 'ABILITY_SHADOW_SHIELD',
    'ABILITY_PRISMARMOR': 'ABILITY_PRISM_ARMOR',
    'ABILITY_INTREPIDSWORD': 'ABILITY_INTREPID_SWORD',
    'ABILITY_DAUNTLESSSHIELD': 'ABILITY_DAUNTLESS_SHIELD',
    'ABILITY_COTTONDOWN': 'ABILITY_COTTON_DOWN',
    'ABILITY_PROPELLERTAIL': 'ABILITY_PROPELLER_TAIL',
    'ABILITY_MIRRORARMOR': 'ABILITY_MIRROR_ARMOR',
    'ABILITY_GULPMISSILE': 'ABILITY_GULP_MISSILE',
    'ABILITY_STEAMENGINE': 'ABILITY_STEAM_ENGINE',
    'ABILITY_PUNKROCK': 'ABILITY_PUNK_ROCK',
    'ABILITY_SANDSPIT': 'ABILITY_SAND_SPIT',
    'ABILITY_ICESCALES': 'ABILITY_ICE_SCALES',
    'ABILITY_ICEFACE': 'ABILITY_ICE_FACE',
    'ABILITY_POWERSPOT': 'ABILITY_POWER_SPOT',
    'ABILITY_SCREENCLEANER': 'ABILITY_SCREEN_CLEANER',
    'ABILITY_STEELYSPIRIT': 'ABILITY_STEELY_SPIRIT',
    'ABILITY_PERISHBODY': 'ABILITY_PERISH_BODY',
    'ABILITY_WANDERINGSPIRIT': 'ABILITY_WANDERING_SPIRIT',
    'ABILITY_GORILLATACTICS': 'ABILITY_GORILLA_TACTICS',
    'ABILITY_NEUTRALIZINGGAS': 'ABILITY_NEUTRALIZING_GAS',
    'ABILITY_PASTELVEIL': 'ABILITY_PASTEL_VEIL',
    'ABILITY_HUNGERSWITCH': 'ABILITY_HUNGER_SWITCH',
    'ABILITY_QUICKDRAW': 'ABILITY_QUICK_DRAW',
    'ABILITY_UNSEENFIST': 'ABILITY_UNSEEN_FIST',
    'ABILITY_CURIOUSMEDICINE': 'ABILITY_CURIOUS_MEDICINE',
    'ABILITY_DRAGONSMAW': 'ABILITY_DRAGONS_MAW',
    'ABILITY_CHILLINGNEIGH': 'ABILITY_CHILLING_NEIGH',
    'ABILITY_GRIMNEIGH': 'ABILITY_GRIM_NEIGH',
    'ABILITY_ASONEICE': 'ABILITY_AS_ONE_ICE_RIDER',
    'ABILITY_ASONESHADOW': 'ABILITY_AS_ONE_SHADOW_RIDER',
    'ABILITY_LINGERINGAROMA': 'ABILITY_LINGERING_AROMA',
    'ABILITY_SEEDSOWER': 'ABILITY_SEED_SOWER',
    'ABILITY_THERMALEXCHANGE': 'ABILITY_THERMAL_EXCHANGE',
    'ABILITY_ANGERSHELL': 'ABILITY_ANGER_SHELL',
    'ABILITY_PURIFYINGSALT': 'ABILITY_PURIFYING_SALT',
    'ABILITY_WELLBAKEDBODY': 'ABILITY_WELL_BAKED_BODY',
    'ABILITY_WINDRIDER': 'ABILITY_WIND_RIDER',
    'ABILITY_GUARDDOG': 'ABILITY_GUARD_DOG',
    'ABILITY_ROCKYPAYLOAD': 'ABILITY_ROCKY_PAYLOAD',
    'ABILITY_WINDPOWER': 'ABILITY_WIND_POWER',
    'ABILITY_ZEROTOHERO': 'ABILITY_ZERO_TO_HERO',
    'ABILITY_GOODASGOLD': 'ABILITY_GOOD_AS_GOLD',
    'ABILITY_VESSELOFRUIN': 'ABILITY_VESSEL_OF_RUIN',
    'ABILITY_SWORDOFRUIN': 'ABILITY_SWORD_OF_RUIN',
    'ABILITY_TABLETSOFRUIN': 'ABILITY_TABLETS_OF_RUIN',
    'ABILITY_BEADSOFRUIN': 'ABILITY_BEADS_OF_RUIN',
    'ABILITY_ORICHALCUMPULSE': 'ABILITY_ORICHALCUM_PULSE',
    'ABILITY_HADRONENGINE': 'ABILITY_HADRON_ENGINE',
    'ABILITY_CUDCHEW': 'ABILITY_CUD_CHEW',
    'ABILITY_SUPREMEOVERLORD': 'ABILITY_SUPREME_OVERLORD',
    'ABILITY_TOXICDEBRIS': 'ABILITY_TOXIC_DEBRIS',
    'ABILITY_ARMORTAIL': 'ABILITY_ARMOR_TAIL',
    'ABILITY_EARTHEATER': 'ABILITY_EARTH_EATER',
    'ABILITY_MYCELIUMMIGHT': 'ABILITY_MYCELIUM_MIGHT',
    'ABILITY_MINDSEYE': 'ABILITY_MINDS_EYE',
    'ABILITY_EMBODYASPECTTEALMASK': 'ABILITY_EMBODY_ASPECT_TEAL_MASK',
    'ABILITY_EMBODYASPECTHEARTHFLAMEMASK': 'ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK',
    'ABILITY_EMBODYASPECTWELLSPRINGMASK': 'ABILITY_EMBODY_ASPECT_WELLSPRING_MASK',
    'ABILITY_EMBODYASPECTCORNESTONEMASK': 'ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK',
    'ABILITY_TOXICCHAIN': 'ABILITY_TOXIC_CHAIN',
    'ABILITY_SUPERSWEETSYRUP': 'ABILITY_SUPERSWEET_SYRUP',
    'ABILITY_TERASHIFT': 'ABILITY_TERA_SHIFT',
    'ABILITY_TERASHELL': 'ABILITY_TERA_SHELL',
    'ABILITY_TERAFORMZERO': 'ABILITY_TERAFORM_ZERO',
    'ABILITY_POISONPUPPETEER': 'ABILITY_POISON_PUPPETEER',
    'ABILITY_LEAFGUARD': 'ABILITY_LEAF_GUARD',
    'ABILITY_WATERBUBBLE': 'ABILITY_WATER_BUBBLE',
    'ABILITY_TINTEDLENS': 'ABILITY_TINTED_LENS',
    'ABILITY_SUPERLUCK': 'ABILITY_SUPER_LUCK',
    'ABILITY_MOLDBREAKER': 'ABILITY_MOLD_BREAKER',
    'ABILITY_BONEZONE': 'ABILITY_BONE_ZONE',
    'ABILITY_BULLRUSH': 'ABILITY_BULL_RUSH',
    'ABILITY_FLAMINGSOUL': 'ABILITY_BLAZING_SOUL',
    'ABILITY_PRIMALARMOR': 'ABILITY_PRIMAL_ARMOR',
    'ABILITY_BADCOMPANY': 'ABILITY_BAD_COMPANY',
    'ABILITY_SAGEPOWER' : 'ABILITY_SAGE_POWER',
    'ABILITY_FELINEPOWER': 'ABILITY_FELINE_PROWESS',
    'ABILITY_SELFSUFFICIENT': 'ABILITY_SELF_SUFFICIENT',
    'ABILITY_LETHALPRECISION': 'ABILITY_FATAL_PRECISION',
    'ABILITY_PHOENIXDOWN': 'ABILITY_PHOENIX_DOWN'
}

# Use the static ability_override_map above for normalization
def normalize_ability_token(token):
    """
    Normalize an ability token using the ability_override_map.
    Returns (normalized_token, reason) where reason is a short explanation
    such as 'exact', 'override', or 'unmapped'.
    """
    if not token:
        return ('ABILITY_NONE', 'empty->NONE')
    t = token.strip()
    # Strip any trailing commas or braces that may accidentally be included
    t = t.rstrip(',}')
    # Check override map first
    if t in ability_override_map:
        return (ability_override_map[t], 'override')
    # Not in override map - return as is
    return (t, 'unmapped')

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
    # parse abilities (.ability1, .ability2, .hiddenAbility)
    for af in ability_fields:
        r = re.search(r"\.%s\s*=\s*([^,\n]+)" % re.escape(af), block)
        if r:
            stats[af] = r.group(1).strip()
    if stats:
        species_map[name] = stats

print(f"Parsed {len(species_map)} species with stats from base_stats_rr.c")

# Process all gen_*_families.h files in the species_info directory (gen_1 .. gen_9)
species_info_dir = Path(r"c:\Users\EBAfa\DeCUMPs\pokeemerald-expansion-fr\src\data\pokemon\species_info")
gen_files = [species_info_dir / f"gen_{i}_families.h" for i in range(1, 10)]

log_lines = []
updated_files = []

for gen_path in gen_files:
    if not gen_path.exists():
        print(f"Skipping missing file: {gen_path}")
        continue
    gen_text = gen_path.read_text(encoding='utf-8')
    orig_text = gen_text

    # For each species found, locate its block in this gen file and replace stat assignments
    for name, stats in species_map.items():
        # find the species occurrence
        m = re.search(r"\[SPECIES_%s\]\s*=\s*\{" % re.escape(name), gen_text)
        if not m:
            continue
        start = m.end()
        i = start
        depth = 1
        while i < len(gen_text) and depth > 0:
            if gen_text[i] == '{':
                depth += 1
            elif gen_text[i] == '}':
                depth -= 1
            i += 1
        block = gen_text[start:i-1]
        new_block = block
        changed = [False]
        for f in fields:
            if f in stats:
                # replace the assignment for this field inside new_block
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
        n_types = 0
        if 'type1' in stats:
            t1 = stats.get('type1')
            t2 = stats.get('type2')
            t1_norm = t1.strip() if t1 else ''
            t2_norm = t2.strip() if t2 else ''
            if not t2_norm or t2_norm == 'TYPE_NONE' or t2_norm == t1_norm:
                types_args = f"{t1_norm}"
            else:
                types_args = f"{t1_norm}, {t2_norm}"
            types_pos = new_block.find('.types')
            if types_pos != -1:
                mon_pos = new_block.find('MON_TYPES', types_pos)
                if mon_pos != -1:
                    paren_start = new_block.find('(', mon_pos)
                    if paren_start != -1:
                        j = paren_start + 1
                        depth_p = 1
                        while j < len(new_block) and depth_p > 0:
                            if new_block[j] == '(':
                                depth_p += 1
                            elif new_block[j] == ')':
                                depth_p -= 1
                            j += 1
                        if depth_p == 0:
                            paren_end = j - 1
                            new_block = new_block[:paren_start+1] + types_args + new_block[paren_end:]
                            n_types = 1

        # Also update abilities if available in stats
        n_abilities = 0
        if any(k in stats for k in ability_fields):
            a1_raw = stats.get('ability1', '').strip()
            a2_raw = stats.get('ability2', '').strip()
            ah_raw = stats.get('hiddenAbility', '').strip()
            a1_norm, r1 = normalize_ability_token(a1_raw) if a1_raw else ('ABILITY_NONE', 'empty')
            a2_norm, r2 = normalize_ability_token(a2_raw) if a2_raw else ('ABILITY_NONE', 'empty')
            ah_norm, rh = normalize_ability_token(ah_raw) if ah_raw else ('ABILITY_NONE', 'empty')
            abilities_args = f"{a1_norm or 'ABILITY_NONE'}, {a2_norm or 'ABILITY_NONE'}, {ah_norm or 'ABILITY_NONE'}"
            abil_pos = new_block.find('.abilities')
            if abil_pos != -1:
                brace_pos = new_block.find('{', abil_pos)
                if brace_pos != -1:
                    k = brace_pos + 1
                    depth_b = 1
                    while k < len(new_block) and depth_b > 0:
                        if new_block[k] == '{':
                            depth_b += 1
                        elif new_block[k] == '}':
                            depth_b -= 1
                        k += 1
                    if depth_b == 0:
                        brace_end = k - 1
                        old_args = new_block[brace_pos+1:brace_end].strip()
                        new_block = new_block[:brace_pos+1] + ' ' + abilities_args + ' ' + new_block[brace_end:]
                        n_abilities = 1
                        # log the change for manual review — include filename and species name
                        log_lines.append(f"{gen_path.name}: SPECIES_{name}: abilities changed from '{{{old_args}}}' to '{{{abilities_args}}}'")
                        if r1 != 'exact' or r2 != 'exact' or rh != 'exact':
                            log_lines.append(f"  normalization: ability1 {a1_raw} -> {a1_norm} ({r1}), ability2 {a2_raw} -> {a2_norm} ({r2}), hidden {ah_raw} -> {ah_norm} ({rh})")

        if changed[0] or n_types > 0 or n_abilities > 0:
            gen_text = gen_text[:start] + new_block + gen_text[i-1:]

    # If changes were made for this gen file, backup and write
    if gen_text != orig_text:
        bak = gen_path.with_suffix('.h.bak')
        bak.write_text(orig_text, encoding='utf-8')
        gen_path.write_text(gen_text, encoding='utf-8')
        print(f"Updated {gen_path} and wrote backup to {bak}")
        updated_files.append(gen_path)

# write abilities change log if any
if log_lines:
    log_path = Path(__file__).with_name('update_gen1_stats.log')
    header = 'Update log for update_gen1_stats.py\n'
    header += 'Note: entries list filename, species and abilities replacement performed.\n\n'
    existing = ''
    if log_path.exists():
        existing = log_path.read_text(encoding='utf-8')
    log_path.write_text(header + existing + '\n'.join(log_lines) + '\n', encoding='utf-8')

if not updated_files:
    print("No changes needed; all gen files already match Base_Stats for specified fields.")
else:
    print(f"Updated {len(updated_files)} files.")
