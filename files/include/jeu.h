#ifndef JEU_H
#define JEU_H

#include "interaction.h"
#include "menu.h"
#include "scene.h"

#define FRAME_PER_SECONDS 12

class Jeu {
    protected:
        Interaction inter;
        Menu menu;
        Scene sc;

    public:
        void start();

        char first_menu();
        char second_menu(char);
        std::vector<char> print_menu();

        void move_right(std::vector<std::string> &, Joueur &);
        void move_left(std::vector<std::string> &, Joueur &);

        void game_start(Joueur, Joueur, std::string);
        
};


#endif // JEU_H