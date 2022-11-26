#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <unistd.h>
#include <vector>

#include "joueur.h"

/* Définition de CLEAN_SCREEN */
#ifdef _WIN32
    #define CLEAN_SCREEN "cls"
#else
    #define CLEAN_SCREEN "clear"
#endif

/* Définition des tailles de l'écran */
#define WIDTH_MENU 65
#define HEIGH_MENU 10



/* FONCTIONS UTILTAIRES *********************************************************************/

/* Affiche un séparateur */
void separator();

/* Affiche un texte au centre de l'écran */
void text_center(std::string);

/* Affiche la première ligne d'un écran */
void print_first_line(std::string);

/* Affiche une barre de chargement */
void loading_bar();



/* AFFICHAGE DES MENUS **********************************************************************/

/* Retourne les choix possibles du premier menu */
std::vector<char> first_menu();

/* Retourne les choix possibles du troisième menu */
std::vector<char> choose_your_scene();

/* Affichage de l'écran du gagnant
* Retourne 2 si la partie continue
           3 sinon
*/
int print_win(int, Joueur, Joueur);

/* Affichage du menu à la fin du jeu */
std::vector<char> print_menu_endgame();



/********************************************************************************************/

#endif // MENU_H