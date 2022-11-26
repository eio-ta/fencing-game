#include "../include/scene.h"

/* Charger une scène avec un fichier *********************************************************/

int count_occurence(std::string scene) {
	int c1 = 0;
	int c2 = 0;
	for(int i=0; i<scene.length(); ++i) {
		if(scene[i] == '1') c1 += 1;
		if(scene[i] == '2') c2 += 1;
	}
	return (c1 == 1 && c2 ==1);
}

std::string load_a_scene(std::string filename) {
    std::ifstream in_stream;
	in_stream.open(filename);
	std::string line;
	if(in_stream.is_open()) {
		in_stream >> line;
		in_stream.close();
	}
	return line;
}

int is_valid_scene(std::string filename) {
	std::ifstream in_stream;
	in_stream.open(filename);
	if(in_stream.is_open()) {
		std::string line;
		int nb_line = 0;
		while(in_stream >> line) {
			nb_line += 1;
		}
		if(nb_line != 1) return false;
		for(int i=0; i<line.length(); ++i) {
			if(!(line[i] == '1' || line[i] == '2' || line[i] == 'x' || line[i] == '_')) {
				return 1;
			}
		}
		in_stream.close();
		if(count_occurence(line) == 0) return 0;
	}
	return 1;
}


/* Charger une scène à partir d'un string ****************************************************/

std::vector<std::string> convert_scene(std::string scene, Joueur &j1, Joueur &j2) {
	std::vector<std::string> lines (HEIGH_MENU, "");
	for(int i=0; i<HEIGH_MENU; ++i) {
        std::string line = "";
        for(int j=0; j<WIDTH_MENU; ++j) {
            line += " ";
        }
        lines[i] = line;
    }
	
	for(int i=0; i<scene.length(); ++i) {
		int new_x = new_x = (i * WIDTH_MENU) / scene.length();
		switch (scene[i]) {
			case '1':
				if(j1.get_dir() == 0) {
					j1.convert_player_r(lines, new_x, 1, HEIGH_MENU);
				} else {
					j1.convert_player_l(lines, new_x, 1, HEIGH_MENU);
				}
				break;
			case '2':
				if(j2.get_dir() == 0) {
					j2.convert_player_r(lines, new_x, 1, HEIGH_MENU);
				} else {
					j2.convert_player_l(lines, new_x, 1, HEIGH_MENU);
				}
				break;
			case 'x':
				lines[HEIGH_MENU-1][new_x] = 'X';
				lines[HEIGH_MENU-1][new_x-1] = 'X';
				lines[HEIGH_MENU-1][new_x+1] = 'X';
				lines[HEIGH_MENU-2][new_x] = 'X';
				lines[HEIGH_MENU-2][new_x-1] = 'X';
				lines[HEIGH_MENU-2][new_x+1] = 'X';
				break;
			default: break;
		}
	}
	return lines;
}

/* Afficher une scène ************************************************************************/

void print_scene(std::vector<std::string> lines, Joueur j1, Joueur j2) {
	print_first_line("FIGHT !");

	std::string line_p = "| " + std::to_string(j1.get_point()) + " | " + std::to_string(j2.get_point()) + " |";
	text_center(line_p);

    for(int i = 0; i < HEIGH_MENU; ++i) {
        std::cout << lines[i] << std::endl;
    }

	for(int i=0; i<2; ++i) {
		for(int j=0; j<WIDTH_MENU; ++j) {
			std::cout << "#";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	separator();
}