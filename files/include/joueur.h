#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>

class Joueur {
    protected:
        float movement_speed;
        int attacking_range;
        float attacking_speed;
        int defending_range;

        int point;
        int attribute; // 1 = attack, 2 = block, 3 = rest
        int dir; // 0 = right, 1 = left

        int x;
    public:
        Joueur();
        Joueur(int, int, int, int);

        void set_dir(int);
        void set_x(int);
        void set_attribute(int);

        int get_point();
        int get_attribute();
        int get_dir();
        int get_x();
        float get_movement_speed();
        float get_attacking_speed();

        int move_right(std::vector<std::string>, int, int);
        int move_left(std::vector<std::string>, int, int);
        int jump_right(std::vector<std::string>, int, int);
        int jump_left(std::vector<std::string>, int, int);

        int attack(Joueur); // 0 = point, 1 = pas de point
         
};

#endif // JOUEUR_H