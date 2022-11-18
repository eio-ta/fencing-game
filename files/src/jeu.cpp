#include "../include/jeu.h"


/// AFFICHER LE MENU ///////////////////////////////////////////////////////////////////////////

char Jeu::first_menu() {
    std::vector<char> v = menu.first_menu();
    char c1 = inter.make_choice(v);
    system(CLEAN_SCREEN);
    return c1;
}

char Jeu::second_menu(char c1) {
    std::vector<char> v = menu.choose_your_scene();
    char c2 = inter.make_choice(v);
    if(c2 == '1') {
        std::string space (20, ' ');
        std::cout << "\r" << space;
        // menu.loading_bar();
        system(CLEAN_SCREEN);
    } else if(c2 == '3') system(CLEAN_SCREEN);
    return c2;
}

std::vector<char> Jeu::print_menu() {
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;

    //menu.loading_bar();

    c1 = Jeu::first_menu();
    c2 = Jeu::second_menu(c1);

    while(c2 == '3') {
        c1 = Jeu::first_menu();
        c2 = Jeu::second_menu(c1);
    }

    std::vector<char> v {c1, c2};
    return v;
}

////////////////////////////////////////////////////////////////////////////////////////////////


/// QUE LE JEU COMMENCE ! //////////////////////////////////////////////////////////////////////

void Jeu::move_right(std::vector<std::string> &grid, Joueur &j) {
    if(j.move_right(grid, WIDTH_SCENE, HEIGH_SCENE) == 0) {
        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()+1);
        sc.replace_player_r(grid, j);
    }
}

void Jeu::move_left(std::vector<std::string> &grid, Joueur &j) {
    if(j.move_left(grid, WIDTH_SCENE, HEIGH_SCENE) == 0) {
        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()-1);
        sc.replace_player_l(grid, j);
    }
}


void Jeu::game_start(Joueur j1, Joueur j2, std::string scene) {
    std::vector<std::string> grid = sc.convert_scene(scene, j1, j2);
    sc.print_scene(grid, j1, j2);

    while(true){
        std::vector<char> mov1 {'d', 'q', '\033'};
        char choice = inter.make_choice(mov1);
        switch(choice) {
            case 'd':
                Jeu::move_right(grid, j1);
                sleep(j1.get_movement_speed()/FRAME_PER_SECONDS);
                break;
            case 'q':
                Jeu::move_left(grid, j1);
                sleep(j1.get_movement_speed()/FRAME_PER_SECONDS);
                break;
            case '\033':
                choice = getchar();
                choice = getchar();
                switch(choice) {
                    case 'C':
                        Jeu::move_right(grid, j2);
                        sleep(j2.get_movement_speed()/FRAME_PER_SECONDS);
                        break;
                    case 'D':
                        Jeu::move_left(grid, j2);
                        sleep(j2.get_movement_speed()/FRAME_PER_SECONDS);
                        break;
                    default: break;
                }
                break;
            default: break;
        }

        system(CLEAN_SCREEN);
        sc.print_scene(grid, j1, j2);
    }

}


///////////////////////////////////////////////////////////////////////////////////////////////


/// FONCTION PRINCIPALE ///////////////////////////////////////////////////////////////////////

void Jeu::start() {
    std::vector<char> choice = Jeu::print_menu();

    // CHOISIR LA SCENE
    std::string scene = "____1___________2___";
    if(choice[1] == '2') {
        scene = sc.load_a_scene("");

        std::cout << "\r" << "Nom du fichier : ";
        std::string filename;
        std::cin >> filename;
        while(!sc.is_valid_scene(filename)) {
            std::cout << "Mauvais fichier ! Donnez un bon chemin relatif : ";
            std::cin >> filename;
        }
        scene = sc.load_a_scene(filename);
    }

    // CHOISIR LES PERSONNAGES
    Joueur j1;
    Joueur j2;
    j2.set_dir();

    Jeu::game_start(j1, j2, scene);
}