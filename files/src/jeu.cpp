#include "../include/jeu.h"


/* AFFICHER LE MENU ET FAIRE SON CHOIX ******************************************************/

char print_first_menu() {
    std::vector<char> v = first_menu();
    char c1 = make_choice(v);
    system(CLEAN_SCREEN);
    return c1;
}

char second_menu(char c1) {
    std::vector<char> v = choose_your_scene();
    char c2 = make_choice(v);
    if(c2 == '1') {
        // loading_bar();
        system(CLEAN_SCREEN);
    } else if(c2 == '3') system(CLEAN_SCREEN);
    return c2;
}

std::vector<char> print_menu() {
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
    // loading_bar();
    c1 = print_first_menu();
    c2 = second_menu(c1);
    while(c2 == '3') {
        c1 = print_first_menu();
        c2 = second_menu(c1);
    }
    std::vector<char> v {c1, c2};
    return v;
}



/* Que le jeu commence ! ********************************************************************/

int player_move_check1(char choice, int fps, Joueur &j, int &j_move_frame, char &j_move, int &j_effect) {
    switch(choice) {
        case 'd':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % FRAMES_PER_S;
                j_move = 'd';
                j.set_can_move(1);
            }
            return 0;
        case 'q':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % FRAMES_PER_S;
                j_move = 'q';
                j.set_can_move(1);
            }
            return 0;
        case 'e':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % FRAMES_PER_S;
                j_move = 'e';
                j_effect = 0;
                j.set_can_move(1);
            }
            return 0;
        case 'a':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % FRAMES_PER_S;
                j_move = 'a';
                j_effect = 0;
                j.set_can_move(1);
            }
            return 0;
        case 'z':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_attack_speed() + fps) % FRAMES_PER_S;
                j_move = 'z';
                j_effect = 0;
                j.set_can_move(1);
            }
            return 0;
        case 's':
            if(j.get_can_move() == 0) {
                std::cout << "hellotoi" << std::endl;
                j_move_frame = (j.get_movement_speed() + fps) % FRAMES_PER_S;
                j_move = 's';
                j_effect = j.get_block_time();
                j.set_can_move(1);
            }
            return 0;
        default: return 1;
    }
}

// 0 = mouvement fini, 1 = mouvement pas fini, -1 = pas de mouvement, 2 = partie finie
int player_move_check2(int &fps, Joueur &j, Joueur &j2, char &j_move, int &j_effect, std::vector<std::string> &grid) {
    if(j_move == 'd') {
        j.move_right(grid, WIDTH_MENU, HEIGH_MENU);
        return 0;
    } else if(j_move == 'q') {
        j.move_left(grid, WIDTH_MENU, HEIGH_MENU);
        return 0;
    } else if(j_move == 'e') {
        if(j_effect == 0) {
            j.jump_right_pos1(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect = 1;
            return 1;
        } else if(j_effect == 1) {
            j.jump_right_pos2(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect = 2;
            return 1;
        } else {
            j.update_position(grid, WIDTH_MENU, HEIGH_MENU, 1);
            return 0;
        }
    } else if(j_move == 'a') {
        if(j_effect == 0) {
            j.jump_left_pos1(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect = 1;
            return 1;
        } else if(j_effect == 1) {
            j.jump_left_pos2(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect = 2;
            return 1;
        } else {
            j.update_position(grid, WIDTH_MENU, HEIGH_MENU, 1);
            return 0;
        }
    } else if(j_move == 'z') {
        if(j_effect == 0) {
            j.move_attack_pos1(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect = 1;
            return 1;
        } else {
            // int tmp = j.get_point();
            // j.add_point(j2);

            // if(j.get_point() != tmp) {
            //     // JOUEUR A MARQUE
            //     return 2;
            // } 
            //     // LE JEU CONTINUE
            j.move_attack_pos2(grid, WIDTH_MENU, HEIGH_MENU);
            return 0;
        }
    } else if(j_move == 's') {
        if(j_effect > 0) {
            j.move_block(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect -= 1;
            std::cout << j_effect << std::endl;
            return 1;
        } else {
            j.move_attack_pos2(grid, WIDTH_MENU, HEIGH_MENU);
            std::cout << j_effect << std::endl;
            return 0;
        }
    } else {
        return -1;
    }
}

void movement_finished(int &j_move_frame, char &j_move, int &j_effect, Joueur &j) {
    j_move_frame = -1;
    j_move = ' ';
    j_effect = -1;
    j.set_can_move(0);
}

void game_start(Joueur j1, Joueur j2, std::string scene) {
    std::vector<std::string> grid = convert_scene(scene, j1, j2);

    int fps = 0;

    int j1_move_frame = -1;
    char j1_move = ' ';
    int j1_effect = -1;

    int j2_move_frame = -1;
    char j2_move = ' ';
    int j2_effect = -1;

    while(true) {
        if(fps == FRAMES_PER_S) {
            fps = 0;   
        }

        if(j1_move_frame == fps) {
            int move_f = player_move_check2(fps, j1, j2, j1_move, j1_effect, grid);
            if(move_f == 0) {
                movement_finished(j1_move_frame, j1_move, j1_effect, j1);
            } else {
                j1_move_frame = (j1_move_frame + 1) % FRAMES_PER_S;
            } 
        }

        if(j2_move_frame == fps) {
            int move_f = player_move_check2(fps, j2, j1, j2_move, j2_effect, grid);
            if(move_f == 0) {
                movement_finished(j2_move_frame, j2_move, j2_effect, j2);
            } else {
                j2_move_frame = (j1_move_frame + 1) % FRAMES_PER_S;
            }
        }


        if(kbhit()) {
            char choice = getchar();
            switch(choice) {
                case 'd': player_move_check1('d', fps, j1, j1_move_frame, j1_move, j1_effect); break;
                case 'q': player_move_check1('q', fps, j1, j1_move_frame, j1_move, j1_effect); break;
                case 'e': player_move_check1('e', fps, j1, j1_move_frame, j1_move, j1_effect); break;
                case 'a': player_move_check1('a', fps, j1, j1_move_frame, j1_move, j1_effect); break;
                case 'z': player_move_check1('z', fps, j1, j1_move_frame, j1_move, j1_effect); break;
                case 's': player_move_check1('s', fps, j1, j1_move_frame, j1_move, j1_effect); break;

                case '\033':
                    choice = getchar();
                    choice = getchar();
                    switch(choice) {
                        case 'C': player_move_check1('d', fps, j2, j2_move_frame, j2_move, j2_effect); break;
                        case 'D': player_move_check1('q', fps, j2, j2_move_frame, j2_move, j2_effect); break;
                        default: break;
                    }
                    break;
                case 'l': player_move_check1('a', fps, j2, j2_move_frame, j2_move, j2_effect); break;
                case 'm': player_move_check1('e', fps, j2, j2_move_frame, j2_move, j2_effect); break;
                case 'o': player_move_check1('z', fps, j2, j2_move_frame, j2_move, j2_effect); break;
                case 'p': player_move_check1('s', fps, j2, j2_move_frame, j2_move, j2_effect); break;
                default: break;
            }
        }

        usleep(10000 * FRAMES_PER_S);

        system(CLEAN_SCREEN);
        print_scene(grid, j1, j2);

        fps += 1;
        std::cout << "Frame : " << fps << std::endl;
    }

}















void start() {
    std::vector<char> choice = print_menu();
    //std::vector<char> choice {'1', '1'};


    /* Scène de combat */
    std::string scene = "_____1_____2____";
    if(choice[1] == '2') {
        std::cout << "\r" << "Nom du fichier : ";
        std::string filename;
        std::cin >> filename;
        while(!is_valid_scene(filename)) {
            std::cout << "Mauvais fichier ! Donnez un bon chemin relatif : ";
            std::cin >> filename;
        }
        
        scene = load_a_scene(filename);

        // loading_bar();
    }

    /* Configutation des joueurs */
    Joueur j1;
    Joueur j2;
    j2.set_dir(1);


    /* START GAME */
    game_start(j1, j2, scene);
}