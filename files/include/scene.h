#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <fstream>

#ifdef _WIN32
    #define CLEAN_SCREEN "cls"
#else
    #define CLEAN_SCREEN "clear"
#endif

#define WIDTH_MENU 60

class Scene {
    public:
        bool count_occurence(std::string);
        void load_a_scene(std::string);
        bool is_valid_scene(std::string);
        
};

#endif // SCENE_H