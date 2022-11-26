#ifndef JEU_H
#define JEU_H

#include "interaction.h"
#include "scene.h"

#define FRAMES_PER_S 8

/* Afficher le menu */

char print_first_menu();
char second_menu(char);
std::vector<char> print_menu();


/* Que le jeu commence ! */

int player_move_check1(char, int, Joueur &, int &, char &, int &);
int player_move_check2(int &, Joueur &, Joueur &, char &, int &, std::vector<std::string> &);
void movement_finished(int &, char &, int &, Joueur &); 

void game_start(Joueur, Joueur, std::string);
void start();


#endif // JEU_H