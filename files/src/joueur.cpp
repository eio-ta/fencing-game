#include "../include/joueur.h"

Joueur::Joueur() {
    this->movement_speed = 5;
    this->attacking_range = 5;
    this->attacking_speed = 8;
    this->defending_range = 5;

    this->point = 0;
    this->attribute = 3;
    this->dir = 0;

    this->x = -1;
}

Joueur::Joueur(int ms, int ar, int as, int dr) {
    this->movement_speed = ms;
    this->attacking_range = ar + 3;
    this->attacking_speed = as;
    this->defending_range = dr + 3;

    this->point = 0;
    this->attribute = 3;
    this->dir = 0;

    this->x = -1;
}

void Joueur::set_dir(int v) {
    if(v == 0 || v == 1) this->dir = v;
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

float Joueur::get_attacking_speed() {
    return this->attacking_speed;
}

void Joueur::set_attribute(int v) {
    if(v == 1 || v == 2 || v == 3) {
        this->attribute = v;
    }
}

int Joueur::move_right(std::vector<std::string> grid, int w, int h) {
    if((this->x + 1) < w-2) {
        if(grid[h-1][(this->x + 1 + 2)] == ' ' && grid[h-1][(this->x + 1 + 4)] == ' ') return 0;
        else return 1;
    } return 1;
}

int Joueur::move_left(std::vector<std::string> grid, int w, int h) {
    if((this->x - 1) > 2) {
        if(grid[h-1][(this->x - 1 - 2)] == ' ' && grid[h-1][(this->x - 1 - 4)] == ' ') return 0;
        else return 1;
    } return 1;
}

int Joueur::jump_right(std::vector<std::string> grid, int w, int h) {
    if(this->x+9 < w-2) {
        for(int i=2; i<10; ++i) {
            if(grid[h-1][(this->x+i)] != ' ' && grid[h-1][(this->x+i)] != 'X') return 1;
        }
        return 0;
    } return 1;
}

int Joueur::jump_left(std::vector<std::string> grid, int w, int h) {
    if(this->x-9 > 2) {
        for(int i=-9; i<-3; ++i) {
            if(grid[h-1][(this->x+i)] != ' ' && grid[h-1][(this->x+i)] != 'X') return 1;
        }
        return 0;
    } return 1;
}

float Joueur::get_movement_speed() {
    return this->movement_speed;
}

int Joueur::attack(Joueur j2) {
    std::cout << "J1->x = " << this->x << std::endl;
    std::cout << "J2.x = " << j2.x << std::endl;

    if(j2.attribute == 2 || j2.attribute == 1) return 1;
    else {
        int dist = j2.x - this->x;
        if(dist > 0) {   // 1_____2
            if(j2.x > (this->attacking_range + this->x)) return 1;
            return 0;
        } else { // 2____1
            if(j2.x < (this->attacking_range - this->x)) return 1;
            return 0;
        }
    }
}