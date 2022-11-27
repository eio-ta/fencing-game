#include "../include/jeu.h"



/* FONCTION PRINCIPALE ***********************************************************************/

int main(int argc, char *argv[]) {
    int frames_per_second = 12;
    if(argc == 2) {
        frames_per_second = atoi(argv[1]);
    } else if(argc > 2) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Erreur syntaxe de la commande : " << std::endl;
        std::cout << "  - ./main <FRAMES_PER_SECONDS> " << std::endl;
        std::cout << "  - ./main " << std::endl;
        std::cout << "--------------------------------" << std::endl;
        return 0;
    }

    start(frames_per_second);
    return 0;
}



/*********************************************************************************************/
