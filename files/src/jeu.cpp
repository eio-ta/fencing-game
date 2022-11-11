#include "../include/jeu.h"

void Jeu::start(std::string scene, int nb_joueur) {
    Joueur joueur1;
    Joueur joueur2;
    joueur2.dir = 1;

    std::string line_point = "| " + std::to_string(joueur1.point) + " | " + std::to_string(joueur2.point) + " |";
    sc.print_text_center(line_point);
    std::vector<std::string> grid = sc.convert_scene(scene, joueur1.x, joueur1.attribut, joueur1.dir, joueur2.x, joueur2.attribut, joueur2.dir);
    sc.print_scene(grid);

    while(true) {
        std::vector<char> mov1 {'q'};
        char choice = inter.make_choice(mov1);
        if(choice = 'q') {
            sc.remove_last_position(grid, joueur1.x);
            joueur1.x += 1;
            sc.replace_new_position(grid, joueur1.x, joueur1.attribut);
            system(CLEAN_SCREEN);
            sc.print_scene(grid);
        }
    }
}