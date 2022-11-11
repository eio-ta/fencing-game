#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "joueur.h"

#ifdef _WIN32
    #define CLEAN_SCREEN "cls"
#else
    #define CLEAN_SCREEN "clear"
#endif

#define WIDTH_MENU 60
#define HEIGH_MENU 10

class Scene {
    public:
        /* Print the text at the center of the box */
        void print_text_center(std::string);
        int count_occurence(std::string);
        std::string load_a_scene(std::string);
        int is_valid_scene(std::string);

        void replace_new_position(std::vector<std::string>&, int &, int &);

        void create_grid_block(std::vector<std::string>&, int, int);
        void create_grid_player_r(std::vector<std::string>&, int, int, int&, int&);
        void create_grid_player_l(std::vector<std::string>&, int, int, int&, int&);
        std::vector<std::string> convert_scene (std::string scene, int &joueur1_x, int &joueur1_attribut, int &joueur1_dir, int &joueur2_x, int &joueur2_attribut, int &joueur2_dir);
        void print_scene(std::vector<std::string> lines);

        void remove_last_position(std::vector<std::string>&, int &);
};

#endif // SCENE_H