import sys
import re
import os

def translator(file_name, output_file_name):
	print(f'{file_name} => {output_file_name}')

	with open(file_name, 'r', encoding='utf-8') as f:
		with open(output_file_name, 'w+', encoding='utf-8') as f2:
			current_macro = None
			for line in f.readlines():
				#print(line)
				if line.startswith('#org'):
					current_macro = line[6:-1]
					#words = current_macro[1:].split('_')
					words = current_macro[1:].split('_')
					fixed_words = [words[1], words[0]]
					if (len(words) > 2):
						fixed_words.extend(words[2:])
					f2.write(f'{'_'.join(fixed_words)}::\n')
					continue
				if len(line.strip()) == 0:
					current_macro = None
					continue
				if current_macro is not None:
					line = line[:-1].strip()
					line = line.replace('[.]', '...')
					line = line.replace('[.', '...') # 3 typo instances i'll account for
					line = line.replace(r'\e', 'é')
					line = line.replace('[GREEN]', '{COLOR GREEN}')
					line = line.replace('[BLUE]', '{COLOR BLUE}')
					line = line.replace('[RED]', '{COLOR RED}')
					line = line.replace('[BLACK]', '{COLOR BLACK}')
					line = line.replace('[SHRINK]', '')
					line = line.replace('[PLAYER]', '{PLAYER}')
					line = line.replace('[RIVAL]', '{RIVAL}')
					line = line.replace('[BUFFER1]', '{STR_VAR_1}')
					line = line.replace('[BUFFER2]', '{STR_VAR_2}')
					line = line.replace('[ARROW_RIGHT]', '{ARROW_RIGHT}')
					line = line.replace('[A_BUTTON]', '{A_BUTTON}')
					line = line.replace('[B_BUTTON]', '{B_BUTTON}')
					line = line.replace('[L_BUTTON]', '{L_BUTTON}')
					line = line.replace('[R_BUTTON]', '{R_BUTTON}')
					blocks = re.findall(r'.*?(?:\\[pln]|$)', line)
					blocks = [block for block in blocks if block]
					blocks[-1] = f'{blocks[-1]}$'
					for block in blocks:
						f2.write(f'  .string "{block}"\n')
					f2.write('\n\n')
					continue

if __name__ == '__main__':
	#if len(sys.argv) < 2:
	#	print('Usage: python translator.py <file_name>')
	#	sys.exit(1)
#
	#file_name = sys.argv[1]

	targets = [r'strings/scripts']
	for target in targets:
		for dir_path, dir_names, file_names in os.walk(target):
			inc_folder = os.path.join(dir_path, 'inc')
			os.makedirs(inc_folder, exist_ok=True)
			for file_name in file_names:
				try:
					translator(os.path.join(dir_path, file_name), os.path.join(inc_folder, file_name.replace('.string', '.inc')))
				except FileNotFoundError:
					print(f'Error no file exists with path: {file_name}')
				except Exception as e:
					print(f'Error reading file: {e}')
			break