#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <unistd.h>

#include "interaction.h"
#include "scene.h"
#include "joueur.h"

class Jeu {
    public:
        Interaction inter;
        Scene sc;
        void start(std::string, int);
};

#endif // JEU_H