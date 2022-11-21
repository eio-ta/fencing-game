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

    // menu.loading_bar();

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
        j.set_dir(0);
        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()+1);
        sc.replace_player_r(grid, j, 1);
    }
}

void Jeu::move_left(std::vector<std::string> &grid, Joueur &j) {
    if(j.move_left(grid, WIDTH_SCENE, HEIGH_SCENE) == 0) {
        j.set_dir(1);
        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()-1);
        sc.replace_player_l(grid, j, 1);
    }
}

void Jeu::jump_right(std::vector<std::string> &grid, Joueur &j, Joueur j2) {
    if(j.jump_right(grid, WIDTH_SCENE, HEIGH_SCENE) == 0) {
        j.set_dir(0);
        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()+4);
        sc.replace_player_r(grid, j, 0);
        system(CLEAN_SCREEN);
        sc.print_scene(grid, j, j2);
        sleep((float) (j.get_movement_speed() / (float) FRAME_PER_SECONDS));

        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()+3);
        sc.replace_player_r(grid, j, 0);
        system(CLEAN_SCREEN);
        sc.print_scene(grid, j, j2);
        sleep((float) (j.get_movement_speed() / (float) FRAME_PER_SECONDS));

        sc.remove_last_position(grid, j);
        sc.replace_player_r(grid, j, 1);
    }
}

void Jeu::jump_left(std::vector<std::string> &grid, Joueur &j, Joueur j2) {
    if(j.jump_left(grid, WIDTH_SCENE, HEIGH_SCENE) == 0) {
        j.set_dir(1);
        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()-4);
        sc.replace_player_l(grid, j, 0);
        system(CLEAN_SCREEN);
        sc.print_scene(grid, j, j2);
        sleep((float) (j.get_movement_speed() / (float) FRAME_PER_SECONDS));

        sc.remove_last_position(grid, j);
        j.set_x(j.get_x()-3);
        sc.replace_player_l(grid, j, 0);
        system(CLEAN_SCREEN);
        sc.print_scene(grid, j, j2);
        sleep((float) (j.get_movement_speed() / (float) FRAME_PER_SECONDS));

        sc.remove_last_position(grid, j);
        sc.replace_player_l(grid, j, 1);
    }
}

void Jeu::attack(std::vector<std::string> &grid, Joueur &j1, Joueur j2) {
    j1.set_attribute(1);
    sc.remove_last_position(grid, j1);
    if(j1.get_dir() == 0) sc.replace_player_r(grid, j1, 1);
    else sc.replace_player_l(grid, j1, 1);
    system(CLEAN_SCREEN);
    sc.print_scene(grid, j1, j2);
    sleep((float) (j1.get_attacking_speed() / (float) FRAME_PER_SECONDS));

    // TODO : COMPTER LES POINTS
    std::cout << j1.attack(j2) << std::endl;

    j1.set_attribute(3);
    sc.remove_last_position(grid, j1);
    if(j1.get_dir() == 0) sc.replace_player_r(grid, j1, 1);
    else sc.replace_player_l(grid, j1, 1);
}

void Jeu::block(std::vector<std::string> &grid, Joueur &j1, Joueur j2) {
    j1.set_attribute(2);
    sc.remove_last_position(grid, j1);
    if(j1.get_dir() == 0) sc.replace_player_r(grid, j1, 1);
    else sc.replace_player_l(grid, j1, 1);
    system(CLEAN_SCREEN);
    sc.print_scene(grid, j1, j2);
    sleep((float) ((float) BLOCKING_TIME / (float) FRAME_PER_SECONDS));

    j1.set_attribute(3);
    sc.remove_last_position(grid, j1);
    if(j1.get_dir() == 0) sc.replace_player_r(grid, j1, 1);
    else sc.replace_player_l(grid, j1, 1);
}

void Jeu::game_start(Joueur j1, Joueur j2, std::string scene) {
    std::vector<std::string> grid = sc.convert_scene(scene, j1, j2);
    sc.print_scene(grid, j1, j2);

    while(true){
        std::vector<char> v {'d', 'q', 'a', 'e', 'z', 's', 'l', 'm', 'o', 'p', '\033'};
        char choice = inter.make_choice(v);
        switch(choice) {
            case 'd':
                sleep((float) (j1.get_movement_speed() / (float) FRAME_PER_SECONDS));
                Jeu::move_right(grid, j1);
                break;
            case 'q':
                sleep((float) (j1.get_movement_speed() / (float) FRAME_PER_SECONDS));
                Jeu::move_left(grid, j1);
                break;
            case 'e':
                sleep((float) (j1.get_movement_speed() / (float) FRAME_PER_SECONDS));
                Jeu::jump_right(grid, j1, j2);
                break;
            case 'a':
                sleep((float) (j1.get_movement_speed() / (float) FRAME_PER_SECONDS));
                Jeu::jump_left(grid, j1, j2);
                break;
            case 'z':
                sleep((float) (j1.get_movement_speed() / (float) FRAME_PER_SECONDS));
                Jeu::attack(grid, j1, j2);
                break;
            case 's':
                sleep((float) (j1.get_movement_speed() / (float) FRAME_PER_SECONDS));
                Jeu::block(grid, j1, j2);
                break;

            case '\033':
                choice = getchar();
                choice = getchar();
                switch(choice) {
                    case 'C':
                        Jeu::move_right(grid, j2);
                        sleep((float) (j2.get_movement_speed() / (float) FRAME_PER_SECONDS));
                        break;
                    case 'D':
                        Jeu::move_left(grid, j2);
                        sleep((float) (j2.get_movement_speed() / (float) FRAME_PER_SECONDS));
                        break;
                    default: break;
                }
                break;
            case 'm':
                Jeu::jump_right(grid, j2, j1);
                sleep((float) (j1.get_movement_speed() / (float) FRAME_PER_SECONDS));
                break;
            case 'l':
                Jeu::jump_left(grid, j2, j1);
                sleep((float) (j2.get_movement_speed() / (float) FRAME_PER_SECONDS));
                break;
            case 'o':
                Jeu::attack(grid, j2, j1);
                sleep((float) (j2.get_movement_speed() / (float) FRAME_PER_SECONDS));
                break;
            case 'p':
                Jeu::block(grid, j2, j1);
                sleep((float) (j2.get_movement_speed() / (float) FRAME_PER_SECONDS));
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

        // menu.loading_bar();
    }

    // CHOISIR LES PERSONNAGES
    Joueur j1;
    Joueur j2;
    j2.set_dir(1);

    Jeu::game_start(j1, j2, scene);
}