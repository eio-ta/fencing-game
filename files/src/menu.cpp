#include "../include/menu.h"

void Menu::separator() {
    std::string str2 = "";
    int size = WIDTH_MENU;
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << str2 << std::endl << std::endl;
}

void Menu::text_center(std::string str) {
    int spacing = (WIDTH_MENU - str.length()) / 2;
    for(int i=0; i<spacing; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}

void Menu::print_first_line(std::string str) {
    std::cout << std::endl << std::endl;
    Menu::text_center(str);
    std::cout << std::endl;
    Menu::separator();
    std::cout << std::endl;
}

void Menu::loading_bar() {
    std::cout << std::endl << std::endl << "  LOADING : ";
    for(int i=0; i<7; ++i) {
        std::cout << "." << std::flush;
        sleep(1);
    }
    std::cout << " 100 %" << std::endl << std::endl;
    sleep(1);
    system(CLEAN_SCREEN);
}

std::vector<char> Menu::first_menu() {
    Menu::print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");

    Menu::text_center("MENU DU JEU :");
    std::cout << std::endl;

    Menu::text_center("1 - PARTIE SIMPLE");
    Menu::text_center("2 - PARTIE PERSONNALISÉE");
    Menu::text_center("3 - CHARGER UNE PARTIE AVEC UN FICHIER");
    std::cout << std::endl;

    Menu::separator();
    std::cout << "Votre réponse : ";

    std::vector<char> v {'1', '2', '3'};
    return v;
}

std::vector<char> Menu::choose_your_scene() {
    Menu::print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");
    
    Menu::text_center("MENU DU JEU :");
    std::cout << std::endl;

    Menu::text_center("1 - SCÈNE PAR DÉFAUT");
    Menu::text_center("2 - CHARGER UNE SCÈNE AVEC UN FICHIER");
    Menu::text_center("3 - RETOUR");
    std::cout << std::endl;

    Menu::separator();
    std::cout << "Votre réponse : ";

    std::vector<char> v {'1', '2', '3'};
    return v;
}