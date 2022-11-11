#ifndef MENU_H
#define MENU_H

#include "jeu.h"

class Menu {
    public:
        /* Print the loading bar */
        void print_loading_bar();

        /* Print the separator */
        void print_separator();

        /* Print the first line of the game */
        void print_first_line_menu();

        /* Print the good menu with the player's choice */
        char interaction_answer(std::vector<char>);

        /* Print the first menu of the game */
        void print_first_menu();

        /* Print the second menu of the game */
        void print_second_menu(char);

        /* Print the third menu of the game */
        void print_third_menu(char, char);

        void print_fight();
};

#endif // MENU_H