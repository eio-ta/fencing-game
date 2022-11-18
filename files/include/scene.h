#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "joueur.h"

#define WIDTH_SCENE 65
#define HEIGH_SCENE 10


class Scene {
    public:
        int count_occurence(std::string);
        int is_valid_scene(std::string);
        std::string load_a_scene(std::string);

        void text_center(std::string);
        void separator();
        void print_first_line(std::string);

        void convert_block(std::vector<std::string>&, int, int);
        void replace_player_r(std::vector<std::string>&, Joueur, int);
        void convert_player_r(std::vector<std::string>&, int, int, Joueur&, int);
        void replace_player_l(std::vector<std::string>&, Joueur, int);
        void convert_player_l(std::vector<std::string>&, int, int, Joueur&, int);
        std::vector<std::string> convert_scene(std::string, Joueur&, Joueur&);

        void remove_last_position(std::vector<std::string>&, Joueur);

        void print_scene(std::vector<std::string>, Joueur, Joueur);
};


#endif // SCENE_H