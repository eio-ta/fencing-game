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
        /* Print the first line of the game */
        void print_first_line_menu();

        /* Print the separator */
        void print_separator();

        /* Print the first menu of the game */
        void print_first_menu();

        /* Print the text at the center of the box */
        void print_text_center(std::string);

        /* Print the good menu with the player's choice */
        void interaction_player();
};

#endif // MENU_H