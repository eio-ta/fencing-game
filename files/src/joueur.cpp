#include "../include/joueur.h"

Joueur::Joueur() {
    this->movement_speed = 2;
    this->attacking_range = 2;
    this->attacking_speed = 2;
    this->defending_range = 2;

    this->point = 0;
    this->attribute = 3;
    this->dir = 0;

    this->x = -1;
}

Joueur::Joueur(int ms, int ar, int as, int dr) {
    this->movement_speed = ms;
    this->attacking_range = ar;
    this->attacking_speed = as;
    this->defending_range = dr;

    this->point = 0;
    this->attribute = 3;
    this->dir = 0;

    this->x = -1;
}

void Joueur::set_dir() {
    if(this->dir == 0) this->dir = 1;
    else this->dir = 0;
}

void Joueur::set_x(int new_x) {
    this->x = new_x;
}

int Joueur::get_point() {
    return this->point;
}

int Joueur::get_attribute() {
    return this->attribute;
}

int Joueur::get_dir() {
    return this->dir;
}

int Joueur::get_x() {
    return this->x;
}

int Joueur::move_right(std::vector<std::string> grid, int w, int h) {
    if((this->x + 1) < w-2) {
        if(grid[h-1][(this->x + 1 + 2)] == ' ') {
            this->x += 1;
            return 0;
        }
        return 1;
    }
    return 1;
}

int Joueur::move_left(std::vector<std::string> grid, int w, int h) {
    if((this->x - 1) > 2) {
        if(grid[h-1][(this->x - 1 - 2)] == ' ') {
            this->x -= 1;
            return 0;
        }
        return 1;
    }
    return 1;
}

int Joueur::get_movement_speed() {
    return this->movement_speed;
}