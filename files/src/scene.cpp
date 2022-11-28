#include "../include/scene.h"



/* CHARGER UNE SCENE ************************************************************************/

/* Compte le nombre d'occurence dans une scène
* Retourne 0 s'il y a bien deux joueurs
*/
int count_occurence(std::string scene) {
	int c1 = 0;
	int c2 = 0;
	for(int i=0; i<scene.length(); ++i) {
		if(scene[i] == '1') c1 += 1;
		if(scene[i] == '2') c2 += 1;
	}
	if(c1 == 1 && c2 == 1) return 0;
	else return 1;
}


/* Récupère une scène à partir d'un fichier */
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


/* Retourne 0 si une scène est valide */
int is_valid_scene(std::string filename) {
	if(filename.length() < 8) return 1;
	std::string substr = filename.substr(filename.length()-8, filename.length()-1);
	if(substr.compare(".ffscene") == 0) {
		std::ifstream in_stream;
		in_stream.open(filename);
		if(in_stream.is_open()) {
			std::string line;
			int nb_line = 0;
			while(in_stream >> line) {
				nb_line += 1;
			}
			if(nb_line != 1) return 1;
			for(int i=0; i<line.length(); ++i) {
				if(!(line[i] == '1' || line[i] == '2' || line[i] == 'x' || line[i] == '_')) {
					return 1;
				}
			}
			in_stream.close();
			if(count_occurence(line) == 0) return 0;
		}
	} else {
		return 1;
	}
	return 1;
}


/* Convertie une scène en un vecteur pour le terminal */
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
				j1.set_x(new_x);
				if(j1.get_dir() == 0) {
					j1.replace_player(lines, 1, HEIGH_MENU, RIGHT);
				} else {
					j1.replace_player(lines, 1, HEIGH_MENU, LEFT);
				}
				break;
			case '2':
				j2.set_x(new_x);
				if(j2.get_dir() == 0) {
					j2.replace_player(lines, 1, HEIGH_MENU, RIGHT);
				} else {
					j2.replace_player(lines, 1, HEIGH_MENU, LEFT);
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


/* Afficher une scène */
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


/* Sauvegarde la partie en cours */
void save_a_game(std::string scene, Joueur &j1, Joueur &j2) {
	std::string l2 = j1.player_to_string();
	std::string l3 = j2.player_to_string();

    std::string input = scene + "\n" + l2 + "\n" + l3;
    std::ofstream out("./data/data.txt");
    out << input;
    out.close();
}


/* Transforme les données d'un fichier de sauvegarde en STRING */
std::string load_data_file() {
	std::string res = "";
    std::ifstream in_stream;
	in_stream.open("./data/data.txt");
	if(in_stream.is_open()) {
		std::string line;
		while(!in_stream.eof()) {
			std::getline(in_stream, line);
			res += line + "\n";
		}
		in_stream.close();
		remove("./data/data.txt");
	}
	return res;
}


/* Transforme les données d'un fichiers en personnage */
void load_data_file_to_player(Joueur &j, std::string data) {
	std::vector<std::string> res_s = split_delim(data, 0);
	std::vector<int> res_i;

	for(std::vector<std::string>::iterator it = res_s.begin() ; it != res_s.end(); ++it) {
        res_i.push_back(stoi(*it));
    }
    
	Joueur tmp {res_i[0], res_i[1], res_i[2], res_i[3], res_i[4]};
	j.copy(tmp);
}



/********************************************************************************************/
