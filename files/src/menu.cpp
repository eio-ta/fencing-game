#include "../include/menu.h"

/* Print the text at the center of the box */
void Menu::print_text_center(std::string str) {
    int spacing = (WIDTH_MENU - str.length()) / 2;
    for(int i=0; i<spacing; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}

/* Print the first menu of the game */
void Menu::print_first_menu() {
    print_text_center("MENU OF THE GAME");
    std::cout << std::endl;

    print_text_center("1 - ONE PLAYER");
    print_text_center("2 - TWO PLAYER");
    std::cout << std::endl;
}

void Menu::interaction_player() {
    Menu::print_first_menu();
    while(true) {
        
    }

}