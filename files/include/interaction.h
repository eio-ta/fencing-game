#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include <vector>

#include "conio.h"



/* ÉVÈNEMENTS AVEC L'UTILISATEUR ************************************************************/

/* Retourne TRUE si l'élément est dans le vecteur */
int is_contains(std::vector<char>, char);

/* Retourne le caractère choisi dans un vecteur */
char make_choice(std::vector<char>);



/********************************************************************************************/

#endif // INTERACTION_H