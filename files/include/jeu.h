#ifndef JEU_H
#define JEU_H

#include <iostream>

#include "interaction.h"
#include "scene.h"
#include "joueur.h"

class Jeu {
    public:
        Interaction inter;
        Scene sc;

        void print_scene_battle(Joueur, Joueur, std::vector<std::string>);

        void start(std::string, int);

        bool move_right(std::vector<std::string> &, Joueur &);
        bool move_left(std::vector<std::string> &, Joueur &);
};

#endif // JEU_H