#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#define WIDTH_MENU 60

class Menu {
    public:
        void print_first_menu();
        void print_text_center(std::string);
        void interaction_player();

};

#endif // MENU_H