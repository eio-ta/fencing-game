#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <unistd.h>
#include <vector>

#ifdef _WIN32
    #define CLEAN_SCREEN "cls"
#else
    #define CLEAN_SCREEN "clear"
#endif

#define WIDTH_MENU 65

class Menu {
    public:
        void separator();
        void text_center(std::string);
        void print_first_line(std::string);

        void loading_bar();

        std::vector<char> first_menu();
        std::vector<char> choose_number_player();
        std::vector<char> choose_your_scene();
};


#endif // MENU_H