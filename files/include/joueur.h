#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>

/* Classe Objet Joueur
* Représente un joueur dans le jeu
*/

class Joueur {

    protected:

        /* Attributs */
        float movement_speed = 1;
        int attacking_range;
        float attacking_speed = 1;
        int defending_range;
        int block_time = 3;

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
        int can_move = 0;



    public:



        /* CONSTRUCTEURS *********************************************************************/

        Joueur();
        Joueur(int, int);



        /* MODIFICATEURS ET ACCESSEURS *******************************************************/

        int get_dir();
        void set_dir(int);

        int get_point();

        int get_movement_speed();
        int get_attack_speed();
        int get_block_time();

        int get_can_move();
        void set_can_move(int);

        void set_attribute(int);



        /* MOUVEMENTS ************************************************************************/

        /* Bouge le personnage vers la droite */
        int can_move_right(std::vector<std::string>, int, int);
        void move_right(std::vector<std::string> &, int, int);

        /* Bouge le personnage vers la gauche */
        int can_move_left(std::vector<std::string>, int, int);
        void move_left(std::vector<std::string> &, int, int);

        /* Fais sauter le personnage vers la droite */
        int can_jump_right(std::vector<std::string>, int, int);
        void jump_right_pos1(std::vector<std::string> &, int, int);
        void jump_right_pos2(std::vector<std::string> &, int, int);

        /* Fais sauter le personnage vers la gauche */
        int can_jump_left(std::vector<std::string> grid, int w, int h);
        void jump_left_pos1(std::vector<std::string> &, int, int);
        void jump_left_pos2(std::vector<std::string> &, int, int);

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
        void replace_player_r(std::vector<std::string>&, int, int);
        void convert_player_r(std::vector<std::string>&, int, int, int);

        /* Affiche un personnage vers la direction GAUCHE sur une scène */
        void replace_player_l(std::vector<std::string>&, int, int);
        void convert_player_l(std::vector<std::string>&, int, int, int);



        /* SUPPRESSION DU TERMINAL ***********************************************************/

        /* Supprime le personnage d'une scène */
        void remove_position(std::vector<std::string>&, int);

        /* Supprime un personnage d'une scène et ajoute sa nouvelle position */
        void update_position(std::vector<std::string>&, int, int, int);



        /* MISE À 0 DU JOUEUR ****************************************************************/

        /* Remet un personnage les attributs d'orginie */
        void update_player();



        /*************************************************************************************/

};

#endif // JOUEUR_H