#include "../include/menu.h"



/* FONCTIONS UTILTAIRES *********************************************************************/

/* Affiche un séparateur */
void separator() {
    std::string str2 = "";
    int size = WIDTH_MENU;
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << str2 << std::endl << std::endl;
}


/* Affiche un texte au centre de l'écran */
void text_center(std::string str) {
    int spacing = (WIDTH_MENU - str.length()) / 2;
    for(int i=0; i<spacing; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}


std::vector<std::string> split_delim(std::string data, int delim) {
    std::vector<std::string> res;
	std::string attri = "";
    char c = (delim == 1) ? '\n' : ' ';

	for(int i=0; i<data.length(); ++i) {
		if(data[i] != c) {
			attri += data[i];
        } else {
        	res.push_back(attri);
			attri = "";
        }
    }
    return res;
}









/* Affiche la première ligne d'un écran */
void print_first_line(std::string str) {
    std::cout << std::endl << std::endl;
    text_center(str);
    std::cout << std::endl;
    separator();
    std::cout << std::endl;
}


/* Affiche une barre de chargement */
void loading_bar() {
    std::cout << std::endl << std::endl << "  LOADING : ";
    for(int i=0; i<5; ++i) {
        std::cout << "." << std::flush;
        sleep(1);
    }
    std::cout << " 100 %" << std::endl << std::endl;
    sleep(1);
    system(CLEAN_SCREEN);
}



/* AFFICHAGE DES MENUS **********************************************************************/

/* Retourne les choix possibles du premier menu */
std::vector<char> first_menu() {
    print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");

    text_center("Menu du jeu :");
    std::cout << std::endl;

    text_center("1 - Partie simple");
    text_center("2 - Charger une partie");
    text_center("3 - Quitter");
    std::cout << std::endl;

    separator();
    
    std::vector<char> v {'1', '2', '3'};
    return v;
}


/* Retourne les choix possibles du deuxième menu */
std::vector<char> second_menu() {
    print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");
    
    text_center("Menu du jeu :");
    std::cout << std::endl;

    text_center("1 - Scène par défaut");
    text_center("2 - Importer une scène");
    text_center("3 - Retour");
    std::cout << std::endl;

    separator();

    std::vector<char> v {'1', '2', '3'};
    return v;
}


/* Retourne les choix possibles du troisième menu */
std::vector<char> third_menu() {
    print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");
    
    text_center("Scène du jeu :");
    std::cout << std::endl;

    text_center("1 - ________1_______x________2___");
    text_center("2 - ________1________________2___");
    std::cout << std::endl;

    separator();
            
    std::vector<char> v {'1', '2'};
    return v;
}

int print_loading_game(int echo) {
    int valid_data = 1;
    std::ifstream in_stream;
	in_stream.open("./data/data.txt");
	if(in_stream.is_open()) {
        valid_data = 0;
		in_stream.close();
	}

    if(valid_data == 0) {
        if(echo == 0) {
            std::cout << "Données de jeu trouvées !" << std::endl;
            loading_bar();
        }
        return 0;

    } else {
        if(echo == 0) {
            std::cout << "Il n'y a pas de données de jeu..." << std::endl;
            std::cout << "Choisissez une autre option." << std::endl;
        }
        return -1;
    }
}







/* Affiche le menu de pause durant une partie */
std::vector<char> menu_pause() {
    system(CLEAN_SCREEN);
	print_first_line("PAUSE");

	text_center("Instructions :");
	std::cout << std ::endl;

    text_center("---------- JOUEUR 1 ----------");
    text_center("'q' : Aller vers la gauche. ");
    text_center("'d' : Aller vers la droite. ");
    text_center("'a' : Sauter vers la gauche.");
    text_center("'e' : Sauter vers la droite.");
    text_center("'z' : Attaque le joueur 2.  ");
    text_center("'s' : Bloque les attaques.  ");
    std::cout << std::endl << std::endl;
    text_center("---------- JOUEUR 2 ----------");
    text_center("'ARROW LEFT' : Aller vers la gauche. ");
    text_center("'ARROW RIGHT' : Aller vers la droite. ");
    text_center("'l' : Sauter vers la gauche.");
    text_center("'m' : Sauter vers la droite.");
    text_center("'o' : Attaque le joueur 2.  ");
    text_center("'p' : Bloque les attaques.  ");
    std::cout << std ::endl;

    separator();
    std::cout << std ::endl;

    text_center("1 - Reprendre la partie.");
    text_center("2 - Sauvegarder la partie et quitter le jeu.");
    text_center("3 - Revenir au menu.");
    std::cout << std::endl;

	separator();

    std::vector<char> v {'1', '2', '3'};

    return v;
}


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

    loading_bar();
	
	if(j1.get_point() >= 3 || j2.get_point() >= 3) return 3;
	return 2;
}


/* Affichage du menu à la fin du jeu */
std::vector<char> print_menu_endgame() {
    system(CLEAN_SCREEN);
	print_first_line("Fin du jeu !");

    text_center("1 - Recommencer avec les mêmes paramètres");
    text_center("2 - Revenir au menu");
    std::cout << std::endl << std::endl;

    separator();

    std::vector<char> v {'1', '2'};
    return v;
}



/********************************************************************************************/
