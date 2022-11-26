#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>

class Joueur {
    protected:
        float movement_speed = 1;
        int attacking_range;
        float attacking_speed = 1;
        int defending_range;
        int block_time = 3;

        int point = 0;
        int attribute = 3; // 1 = attack, 2 = block, 3 = rest
        int dir = 0; // 0 = right, 1 = left

        int x = -1;
        int can_move = 0; // 0 = OUI, 1 = NON
    public:

        /* Constructeurs */

        Joueur();
        Joueur(int, int);


        /* Modificateurs et accesseurs */

        int get_dir();
        void set_dir(int);

        int get_point();

        int get_movement_speed();
        int get_attack_speed();
        int get_block_time();

        int get_can_move();
        void set_can_move(int);

        void set_attribute(int);

        /* Mouvements */

        int can_move_right(std::vector<std::string>, int, int);
        void move_right(std::vector<std::string> &, int, int);

        int can_move_left(std::vector<std::string>, int, int);
        void move_left(std::vector<std::string> &, int, int);

        int can_jump_right(std::vector<std::string>, int, int);
        void jump_right_pos1(std::vector<std::string> &, int, int);
        void jump_right_pos2(std::vector<std::string> &, int, int);

        int can_jump_left(std::vector<std::string> grid, int w, int h);
        void jump_left_pos1(std::vector<std::string> &, int, int);
        void jump_left_pos2(std::vector<std::string> &, int, int);

        void move_attack_pos1(std::vector<std::string> &, int, int);
        void move_attack_pos2(std::vector<std::string> &, int, int);
        int attack(Joueur j2);
        void add_point(Joueur);

        void move_block(std::vector<std::string> &, int, int);        


        /* Affichage sur la scène */

        void replace_player_r(std::vector<std::string>&, int, int);
        void convert_player_r(std::vector<std::string>&, int, int, int);
        void replace_player_l(std::vector<std::string>&, int, int);
        void convert_player_l(std::vector<std::string>&, int, int, int);


        /* Supprimer l'affichage d'un joueur */

        void remove_position(std::vector<std::string>&, int);
        void update_position(std::vector<std::string>&, int, int, int);
       
};

#endif // JOUEUR_H