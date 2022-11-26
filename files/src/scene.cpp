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
	std::ifstream in_stream;
	in_stream.open(filename);
	if(in_stream.is_open()) {
		std::string line;
		int nb_line = 0;
		while(in_stream >> line) {
			nb_line += 1;
		}
		std::cout << "test1";
		if(nb_line != 1) return 1;
		for(int i=0; i<line.length(); ++i) {
			if(!(line[i] == '1' || line[i] == '2' || line[i] == 'x' || line[i] == '_')) {
				std::cout << "test2";
				return 1;
			}
		}
		in_stream.close();
		std::cout << "test3";
		if(count_occurence(line) == 0) return 0;
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



/* AFFICHAGE DES DIFFERENTS PANNEAUX ********************************************************/

/* Affichage de l'écran du gagnant
* Retourne 2 si la partie continue
           3 sinon
*/
int print_win(int nb, Joueur j1, Joueur j2) {
	system(CLEAN_SCREEN);
	print_first_line("BRAVO !");

	std::string line_p;
	if(nb == 1) {
		line_p = "| " + std::to_string(j1.get_point()) + " | " + std::to_string(j2.get_point()) + " |";
	} else {
		line_p = "| " + std::to_string(j2.get_point()) + " | " + std::to_string(j1.get_point()) + " |";
	}
	text_center(line_p);
	std::cout << std ::endl << std::endl;

	text_center("Joueur " + std::to_string(nb) + " a gagné un point !");
	std::cout << std ::endl << std::endl;
	separator();
	
	if(j1.get_point() >= 3 || j2.get_point() >= 3) {
		// TODO : JEU TERMINE
		return 3;
	}

	loading_bar();
	return 2;
}



/********************************************************************************************/
