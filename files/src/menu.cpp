#include "../include/menu.h"

void separator() {
    std::string str2 = "";
    int size = WIDTH_MENU;
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << str2 << std::endl << std::endl;
}

void text_center(std::string str) {
    int spacing = (WIDTH_MENU - str.length()) / 2;
    for(int i=0; i<spacing; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}

void print_first_line(std::string str) {
    std::cout << std::endl << std::endl;
    text_center(str);
    std::cout << std::endl;
    separator();
    std::cout << std::endl;
}

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

std::vector<char> first_menu() {
    print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");

    text_center("Menu du jeu :");
    std::cout << std::endl;

    text_center("1 - Partie simple");
    text_center("2 - Partie personnalisée");
    text_center("3 - Charger une partie avec un fichier");
    std::cout << std::endl;

    separator();
    
    std::vector<char> v {'1', '2', '3'};
    return v;
}

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