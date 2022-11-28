#ifndef SCENE_H
#define SCENE_H

#include "menu.h"



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

/* Sauvegarde la partie en cours */
void save_a_game(std::string, Joueur &, Joueur &);

/* Transforme les données d'un fichier de sauvegarde en STRING */
std::string load_data_file();

/* Transforme les données d'un fichiers en personnage */
void load_data_file_to_player(Joueur &, std::string);


/********************************************************************************************/

#endif // SCENE_H