#include "../include/jeu.h"

bool Jeu::move_left(std::vector<std::string> &grid, Joueur &joueur) {
    if((joueur.x - 1) > 2) {
        std::cout << "f" << std::endl;
        if(grid[HEIGH_MENU-1][(joueur.x - 1 - 2)] == ' ') {
            sc.remove_last_position(grid, joueur.x);
            joueur.x -= 1;
            sc.replace_new_position_l(grid, joueur.x, joueur.attribut);
            return true;
        }
        return false;
    }
    return false;
}

bool Jeu::move_right(std::vector<std::string> &grid, Joueur &joueur) {
    if((joueur.x + 1) < WIDTH_MENU-2) {
        if(grid[HEIGH_MENU-1][(joueur.x + 1 + 2)] == ' ') {
            sc.remove_last_position(grid, joueur.x);
            joueur.x += 1;
            sc.replace_new_position_r(grid, joueur.x, joueur.attribut);
            return true;
        }
        return false;
    }
    return false;
}

void Jeu::print_scene_battle(Joueur joueur1, Joueur joueur2, std::vector<std::string> grid) {
    system(CLEAN_SCREEN);

    sc.print_fight();

    std::string line_point = "| " + std::to_string(joueur1.point) + " | " + std::to_string(joueur2.point) + " |";
    sc.print_text_center(line_point);

    sc.print_scene(grid);
}

void Jeu::start(std::string scene, int nb_joueur) {
    Joueur joueur1;
    Joueur joueur2;
    joueur2.dir = 1;

    std::vector<std::string> grid = sc.convert_scene(scene, joueur1.x, joueur1.attribut, joueur1.dir, joueur2.x, joueur2.attribut, joueur2.dir);
    Jeu::print_scene_battle(joueur1, joueur2, grid);

    while(true) {
        std::vector<int> mov1 {100, KEY_RIGHT, 113, KEY_LEFT};
        int choice = inter.make_choice(mov1);
        switch(choice) {
            case 100:
                if(move_right(grid, joueur1)) Jeu::print_scene_battle(joueur1, joueur2, grid);
                break;
            case KEY_RIGHT:
                if(move_right(grid, joueur2)) Jeu::print_scene_battle(joueur1, joueur2, grid);
                break;
            case 113:
                if(move_left(grid, joueur1)) Jeu::print_scene_battle(joueur1, joueur2, grid);
                break;
            case KEY_LEFT:
                if(move_left(grid, joueur2)) Jeu::print_scene_battle(joueur1, joueur2, grid);
                break;
            default: break;
        }
    }
}