#ifndef JEU_H
#define JEU_H

#include "interaction.h"
#include "scene.h"



/* AFFICHE LE MENU **************************************************************************/

/* Affiche le premier menu */
char print_first_menu();

/* Affiche le second menu */
char print_second_menu(char);

/* Retourne les choix choisis par l'utilisateur pendant le menu */
std::vector<char> print_menu();



/* ÉVÈVENEMENTS LIÉS AVEC LES MOUVEMENTS DES JOUEURS ****************************************/

/* Réalise les mouvements des joueurs
* Retourne 0 si le mouvement a été réalisé
           1 si le mouvement n'a pas été réalisé
*/
int player_move_check1(char, int, Joueur &, int &, char &, int &, int);

/* Réalise les mouvements des joueurs
* Retourne 0 si le mouvement est terminé
           1 si le mouvement doit continuer
          -1 si le mouvement ne s'est pas réalisé
*/
int player_move_check2(int, int &, Joueur &, Joueur &, char &, int &, std::vector<std::string> &, int);

/* Initialise les attributs d'un joueur */
void movement_finished(int &, char &, int &, Joueur &);

/* Vérifie si le jeu n'est pas terminé */
int maybe_endgame(int, Joueur &, Joueur &, int &, char &, int &, std::vector<std::string> &, int);


/* LANCEMENT DU JEU *************************************************************************/

/* Boucle principale du jeu */
int play(Joueur &, Joueur &, std::string, int);

/* Lancement du jeu */
void time_2_play(std::string, Joueur &, Joueur &, int);

/* Lancement du menu */
void start(int);



/********************************************************************************************/

#endif // JEU_H