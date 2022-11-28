#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>

#define RIGHT 1
#define LEFT -1
#define JUMP_RIGHT 7
#define JUMP_LEFT -7

/* Classe Objet Joueur
* Représente un joueur dans le jeu
*/

class Joueur {

    protected:

        /* Attributs */
        float movement_speed = 1;
        int attacking_range;
        float attacking_speed = 5;
        int defending_range;
        int block_time = 5;

        int point = 0;


        /* État du joueur
        * 1 = ATTAQUE
        * 2 = BLOQUE
        * 3 = REPOS
        */
        int attribute = 3;


        /* Direction du personnage (idéal pour l'affichage)
        * 0 = DROITE
        * 1 = GAUCHE
        */
        int dir = 0;


        /* Position du personnage */
        int x = -1;


        /* Peut-il être en mouvement ?
        * 0 = OUI
        1 = NON
        */
        int is_on_movement = 0;



    public:



        /* CONSTRUCTEURS *********************************************************************/

        Joueur();
        Joueur(int, int, int, int, int);



        /* MODIFICATEURS ET ACCESSEURS *******************************************************/

        int get_dir();
        void set_dir(int);

        int get_point();
        void point_0();

        int get_movement_speed();
        int get_attack_speed();
        int get_block_time();

        int get_is_on_movement();
        void set_is_on_movement(int);

        void set_attribute(int);
        void set_x(int);



        /* MOUVEMENTS ************************************************************************/

        /* Vérifie si le joueur peut se déplacer horizontalement */
        int can_move_to(std::vector<std::string>, int, int, int);

        /* Fais bouger le joueur suivant la direction */
        void move_to(std::vector<std::string> &, int, int, int);

        /* Vérifie si le joueur peut sauter */
        int can_jump_to(std::vector<std::string>, int, int, int);

        /* Les différentes positions pour sauter */
        void jump_to_pos1(std::vector<std::string> &, int, int, int);
        void jump_to_pos2(std::vector<std::string> &, int, int, int);

        /* Mets le personnage en mode ATTAQUE */
        void player_attack(std::vector<std::string> &, int, int);

        /* Mets le personnage en mode REST */
        void player_rest(std::vector<std::string> &, int, int);

        /* Mets le personnage en mode BLOQUE */
        void player_block(std::vector<std::string> &, int, int);



        /* ATTAQUE UN AUTRE PERSONNAGE *******************************************************/

        /* Retourne 0 si l'attaque a eu lieu
                    1 sinon
        */
        int attack(Joueur j2);

        /* Rajoute un point si l'attaque a eu lieu */
        void add_point(Joueur);



        /* AFFICHAGE SUR LE TERMINAL *********************************************************/

        /* Affiche un personnage vers la direction DROITE sur une scène */
        void replace_player(std::vector<std::string>&, int, int, int);



        /* SUPPRESSION DU TERMINAL ***********************************************************/

        /* Supprime le personnage d'une scène */
        void remove_position(std::vector<std::string>&, int);

        /* Supprime un personnage d'une scène et ajoute sa nouvelle position */
        void update_position(std::vector<std::string>&, int, int, int, int);



        /* MISE À JOUR DU JOUEUR *************************************************************/

        /* Remet un personnage les attributs d'origine */
        void update_player();

        /* Convertie un personnage en STRING */
        std::string player_to_string();

        /* Copie un joueur */
        void copy(Joueur);



        /*************************************************************************************/

};

#endif // JOUEUR_H