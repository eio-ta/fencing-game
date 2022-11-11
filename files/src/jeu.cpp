#include "../include/jeu.h"

void Jeu::start(std::string scene, int nb_joueur) {
    Humain joueur1;
    Joueur joueur2;
    joueur2.dir = 1;

    std::string line_point = "| " + std::to_string(joueur1.point) + " | " + std::to_string(joueur2.point) + " |";
    sc.print_text_center(line_point);
    sc.print_scene(scene, joueur1, joueur2);
}