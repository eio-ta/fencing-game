#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <unistd.h>
#include <vector>

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

/* Retourne les choix possibles du deuxième menu */
std::vector<char> choose_number_player();

/* Retourne les choix possibles du troisième menu */
std::vector<char> choose_your_scene();



/********************************************************************************************/

#endif // MENU_H