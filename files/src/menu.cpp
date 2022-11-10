#include "../include/menu.h"

Interaction inter;

/* Print the separator */
void Menu::print_separator() {
    std::string str2 = "";
    int size = WIDTH_MENU;
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << str2 << std::endl << std::endl;
}

/* Print the first line of the game */
void Menu::print_first_line_menu() {
    std::string str1 = "   Click on the corresponding button to make your choice.   ";
    std::cout << std::endl << std::endl << str1 << std::endl << std::endl;
    Menu::print_separator();
}

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

// char Menu::check_answer_player() {
//     std::string str2 = "";
//     int size = WIDTH_MENU;
//     for(int i=0; i<size; ++i) {
//         str2 += "_";
//     }
//     std::cout << str2 << std::endl << std::endl;

//     std::cout << "Your answer : ";
//     char tmp;
//     std::cin >> tmp;
//     return tmp;
// }

void Menu::interaction_player() {
    Menu::print_first_menu();

    std::vector<char> v { '1', '2'};
    char choice = inter.make_choice(v);

    if(choice == '1') {
        // TODO: MODE ONE PLAYER
    } else {
        // TODO: MODE TWO PLAYER
    }
}