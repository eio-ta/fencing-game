#ifndef JEU_H
#define JEU_H

#include "interaction.h"
#include "menu.h"
#include "scene.h"

#define FRAME_PER_SECONDS 8
#define BLOCKING_TIME 8

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
        void jump_right(std::vector<std::string> &, Joueur &, Joueur);
        void jump_left(std::vector<std::string> &, Joueur &, Joueur);
        void attack(std::vector<std::string> &, Joueur &, Joueur);
        void block(std::vector<std::string> &, Joueur &, Joueur);

        void game_start(Joueur, Joueur, std::string);
        
};


#endif // JEU_H