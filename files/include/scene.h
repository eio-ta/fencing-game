#ifndef SCENE_H
#define SCENE_H

#include <fstream>

#include "menu.h"
#include "joueur.h"



/* CHARGER UNE SCENE ************************************************************************/

/* Compte le nombre d'occurence dans une scène
* Retourne 0 s'il y a bien deux joueurs
*/
int count_occurence(std::string);

/* Récupère une scène à partir d'un fichier */
std::string load_a_scene(std::string);

/* Retourne 0 si une scène est valide */
int is_valid_scene(std::string);

/* Convertie une scène en un vecteur pour le terminal */
std::vector<std::string> convert_scene(std::string, Joueur &, Joueur &);

/* Afficher une scène */
void print_scene(std::vector<std::string>, Joueur, Joueur);



/* AFFICHAGE DES DIFFERENTS PANNEAUX ********************************************************/

/* Affichage de l'écran du gagnant
* Retourne 2 si la partie continue
           3 sinon
*/
int print_win(int, Joueur, Joueur);



/********************************************************************************************/

#endif // SCENE_H