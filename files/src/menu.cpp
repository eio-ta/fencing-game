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
    text_center("2 - Partie personnalisée");
    text_center("3 - Quitter");
    std::cout << std::endl;

    separator();
    
    std::vector<char> v {'1', '2', '3'};
    return v;
}


/* Retourne les choix possibles du troisième menu */
std::vector<char> choose_your_scene() {
    print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");
    
    text_center("Menu du jeu :");
    std::cout << std::endl;

    text_center("1 - Scène par défaut");
    text_center("2 - Charger une scène avec un fichier");
    text_center("3 - Retour");
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
    std::cout << std::endl;
    std::cout << std::endl;

    separator();

    std::vector<char> v {'1', '2'};
    return v;
}



/********************************************************************************************/
