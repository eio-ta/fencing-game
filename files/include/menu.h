#ifndef MENU_H
#define MENU_H

#include "interaction.h"

#ifdef _WIN32
    #define CLEAN_SCREEN "cls"
#else
    #define CLEAN_SCREEN "clear"
#endif

#define WIDTH_MENU 60

class Menu {
    public:
        /* Print the separator */
        void print_separator();

        /* Print the first line of the game */
        void print_first_line_menu();

        /* Print the text at the center of the box */
        void print_text_center(std::string);

        /* Print the good menu with the player's choice */
        char interaction_answer(std::vector<char>);

        /* Print the first menu of the game */
        void print_first_menu();

        /* Print the second menu of the game */
        void print_second_menu(char);

        /* Print the third menu of the game */
        void print_third_menu(char, char);
};

#endif // MENU_H