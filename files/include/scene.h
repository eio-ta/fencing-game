#ifndef SCENE_H
#define SCENE_H

#include <fstream>

#include "menu.h"
#include "joueur.h"

/* Charger une scène avec un fichier */

int count_occurence(std::string);
std::string load_a_scene(std::string);
int is_valid_scene(std::string);


/* Convertir une scène à partir d'un string */

std::vector<std::string> convert_scene(std::string, Joueur &, Joueur &);

/* Afficher une scène */

void print_scene(std::vector<std::string>, Joueur, Joueur);



#endif // SCENE_H