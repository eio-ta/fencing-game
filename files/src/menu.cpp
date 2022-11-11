#include "../include/menu.h"

Jeu jeu;

void Menu::print_separator() {
    std::string str2 = "";
    int size = WIDTH_MENU;
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << str2 << std::endl << std::endl;
}

void Menu::print_first_line_menu() {
    std::string str1 = "   Click on the corresponding button to make your choice.   ";
    std::cout << std::endl << std::endl << str1 << std::endl << std::endl;
    Menu::print_separator();
}

void Menu::print_text_center(std::string str) {
    int spacing = (WIDTH_MENU - str.length()) / 2;
    for(int i=0; i<spacing; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}

char Menu::interaction_answer(std::vector<char> v) {
    Menu::print_separator();
    std::cout << "Your answer : ";
    return jeu.inter.make_choice(v);
}

void Menu::print_first_menu() {
    Menu::print_first_line_menu();
    print_text_center("MENU OF THE GAME");
    std::cout << std::endl;

    print_text_center("1 - NEW GAME");
    print_text_center("2 - LOAD THE LAST GAME");
    std::cout << std::endl;

    std::vector<char> v { '1', '2'};
    char choice = Menu::interaction_answer(v);

    system(CLEAN_SCREEN);
    if(choice == '1') Menu::print_second_menu(choice);
    else {
        // TODO : CHARGER UNE ANCIENNE PARTIE
    }
}

void Menu::print_second_menu(char choice1) {
    Menu::print_first_line_menu();
    print_text_center("MENU OF THE GAME");
    std::cout << std::endl;

    print_text_center("1 - ONE PLAYER");
    print_text_center("2 - TWO PLAYER");
    print_text_center("3 - BACK");
    std::cout << std::endl;

    std::vector<char> v { '1', '2', '3'};
    char choice2 = Menu::interaction_answer(v);

    system(CLEAN_SCREEN);
    if(choice2 == '3') Menu::print_first_menu();
    Menu::print_third_menu(choice1, choice2);
}

void Menu::print_third_menu(char choice1, char choice2) {
    Menu::print_first_line_menu();
    print_text_center("MENU OF THE GAME");
    std::cout << std::endl;

    print_text_center("1 - NEW SCENE");
    print_text_center("2 - LOAD A SCENE FROM A FILE");
    print_text_center("3 - BACK");
    std::cout << std::endl;

    std::vector<char> v { '1', '2', '3'};
    char choice3 = Menu::interaction_answer(v);

    if(choice3 == '1') {
        // TODO : NOUVELLE SCENE
        system(CLEAN_SCREEN);
    } else if(choice3 == '2') {
        std::cout << "\r" << "The filename : ";
        std::string filename;
        std::cin >> filename;
        while(!jeu.sc.is_valid_scene(filename)) {
            std::cout << "Wrong filename ! Please, give a good filename : ";
            std::cin >> filename;
        }
        system(CLEAN_SCREEN);
        jeu.sc.load_a_scene(filename);
    } else {
        system(CLEAN_SCREEN);
        Menu::print_second_menu(choice2);
    };
}