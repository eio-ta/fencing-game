#include "../include/interaction.h"



/* ÉVÈNEMENTS AVEC L'UTILISATEUR ************************************************************/

/* Retourne TRUE si l'élément est dans le vecteur */
int is_contains(std::vector<char> v, char e) {
    for(std::vector<char>::iterator it = v.begin() ; it != v.end(); ++it) {
        if(e == *it) return 0;
    }
    return 1;
}


/* Retourne le caractère choisi dans un vecteur */
char make_choice(std::vector<char> v) {
    char choice;
    while(1) {
        if(kbhit()) {
            choice = getchar();
            if(is_contains(v, choice) == 0) {
                return choice;
            }
        }
    }
    return '0';
}



/********************************************************************************************/