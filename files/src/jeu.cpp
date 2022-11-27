#include "../include/jeu.h"



/* AFFICHE LE MENU **************************************************************************/

/* Affiche le premier menu */
char print_first_menu() {
    std::vector<char> v = first_menu();
    char c1 = make_choice(v);
    system(CLEAN_SCREEN);
    return c1;
}


/* Affiche le second menu */
char print_second_menu(char c1) {
    std::vector<char> v = choose_your_scene();
    char c2 = make_choice(v);
    if(c2 == '1') {
        // loading_bar();
        system(CLEAN_SCREEN);
    } else if(c2 == '4') system(CLEAN_SCREEN);
    return c2;
}


/* Retourne les choix choisis par l'utilisateur pendant le menu */
std::vector<char> print_menu() {
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;

    // loading_bar();
    c1 = print_first_menu();

    if(c1 == '3' || c1 == '2') {
        std::vector<char> v {c1};
        return v;
    }

    c2 = print_second_menu(c1);
    while(c2 == '4') {
        c1 = print_first_menu();

        if(c1 == '3' || c1 == '2') {
            std::vector<char> v {c1};
            return v;
        }

        c2 = print_second_menu(c1);
    }
    std::vector<char> v {c1, c2};
    return v;
}


/* Affiche l'écran de la pause durant un jeu */
int print_pause() {
    std::vector<char> v = menu_pause();
    char c = make_choice(v);

    if(c == '1') return 1;
    if(c == '2') return 2;
    else return 3;
}



/* ÉVÈVENEMENTS LIÉS AVEC LES MOUVEMENTS DES JOUEURS ****************************************/

/* Réalise les mouvements des joueurs
* Retourne 0 si le mouvement a été réalisé
           1 si le mouvement n'a pas été réalisé
*/
int player_move_check1(char choice, int fps, Joueur &j, int &j_move_frame, char &j_move, int &j_effect, int frames_per_s) {
    switch(choice) {
        case 'd':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % frames_per_s;
                j_move = 'd';
                j.set_can_move(1);
            }
            return 0;
        case 'q':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % frames_per_s;
                j_move = 'q';
                j.set_can_move(1);
            }
            return 0;
        case 'e':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % frames_per_s;
                j_move = 'e';
                j_effect = 0;
                j.set_can_move(1);
            }
            return 0;
        case 'a':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % frames_per_s;
                j_move = 'a';
                j_effect = 0;
                j.set_can_move(1);
            }
            return 0;
        case 'z':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_attack_speed() + fps) % frames_per_s;
                j_move = 'z';
                j_effect = 0;
                j.set_can_move(1);
            }
            return 0;
        case 's':
            if(j.get_can_move() == 0) {
                j_move_frame = (j.get_movement_speed() + fps) % frames_per_s;
                j_move = 's';
                j_effect = j.get_block_time();
                j.set_can_move(1);
            }
            return 0;
        default: return 1;
    }
}


/* Réalise les mouvements des joueurs
* Retourne 0 si le mouvement est terminé
           1 si le mouvement doit continuer
          -1 si le mouvement ne s'est pas réalisé
           2 si la partie est terminée
*/
int player_move_check2(int nb, int &fps, Joueur &j, Joueur &j2, char &j_move, int &j_effect, std::vector<std::string> &grid, int frames_per_s) {
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
            j.player_attack(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect = 1;
            return 1;
        } else {
            int tmp = j.get_point();
            j.add_point(j2);
            
            if(j.get_point() != tmp) {
                return print_win(nb, j, j2);
            }
            j.player_rest(grid, WIDTH_MENU, HEIGH_MENU);
            return 0;
        }
    } else if(j_move == 's') {
        if(j_effect > 0) {
            j.player_block(grid, WIDTH_MENU, HEIGH_MENU);
            j_effect -= 1;
            std::cout << j_effect << std::endl;
            return 1;
        } else {
            j.player_rest(grid, WIDTH_MENU, HEIGH_MENU);
            std::cout << j_effect << std::endl;
            return 0;
        }
    } else {
        return -1;
    }
}


/* Initialise les attributs d'un joueur */
void movement_finished(int &j_move_frame, char &j_move, int &j_effect, Joueur &j) {
    j_move_frame = -1;
    j_move = ' ';
    j_effect = -1;
    j.set_can_move(0);
}


/* Vérifie si le jeu n'est pas terminé */
int maybe_endgame(int nb, int fps, Joueur &j, Joueur &j2, int &j_move_frame, char &j_move, int &j_effect, std::vector<std::string> &grid, int frames_per_s) {
    int move_f = player_move_check2(nb, fps, j, j2, j_move, j_effect, grid, frames_per_s);
    if(move_f == 0) { // Le mouvement est fini, pas de gagnant
        movement_finished(j_move_frame, j_move, j_effect, j);
        return 1;
    } else if(move_f == 1) { // Le jeu continue, pas de gagnant
        j_move_frame = (j_move_frame + 1) % frames_per_s;
        return 1;
    } else if(move_f == 2) { // Le jeu continue, gagnant
        return 2;
    } else { // Le jeu est vraiment terminé
        return 3;
    }
}



/* LANCEMENT DU JEU *************************************************************************/

/* Boucle principale du jeu
* Retourne 0 si le jeu continue
*          1 si le jeu est terminé
*          2 si l'utilisateur a choisi de sauvegarder sa partie
*          3 si l'utilisateur veut revenir au menu
*/
int play(Joueur &j1, Joueur &j2, std::string scene, int frames_per_s) {
    std::vector<std::string> grid = convert_scene(scene, j1, j2);

    int fps = 0;

    int j1_move_frame = -1;
    char j1_move = ' ';
    int j1_effect = -1;

    int j2_move_frame = -1;
    char j2_move = ' ';
    int j2_effect = -1;

    while(true) {
        if(fps == frames_per_s) {
            fps = 0;
        }

        if(j1_move_frame == fps) {
            int tmp = maybe_endgame(1, fps, j1, j2, j1_move_frame, j1_move, j1_effect, grid, frames_per_s);
            if(tmp == 2) return 0; // Le jeu continue, mais gagnant
            if(tmp == 3) return 1; // Le jeu est terminé
        }

        if(j2_move_frame == fps) {
            int tmp = maybe_endgame(2, fps, j2, j1, j2_move_frame, j2_move, j2_effect, grid, frames_per_s);
            if(tmp == 2) return 0; // Le jeu continue, mais gagnant
            if(tmp == 3) return 1; // Le jeu est terminé
        }

        if(kbhit()) {
            char choice = getchar();
            int p;
            switch(choice) {
                case 'd': player_move_check1('d', fps, j1, j1_move_frame, j1_move, j1_effect, frames_per_s); break;
                case 'q': player_move_check1('q', fps, j1, j1_move_frame, j1_move, j1_effect, frames_per_s); break;
                case 'e': player_move_check1('e', fps, j1, j1_move_frame, j1_move, j1_effect, frames_per_s); break;
                case 'a': player_move_check1('a', fps, j1, j1_move_frame, j1_move, j1_effect, frames_per_s); break;
                case 'z': player_move_check1('z', fps, j1, j1_move_frame, j1_move, j1_effect, frames_per_s); break;
                case 's': player_move_check1('s', fps, j1, j1_move_frame, j1_move, j1_effect, frames_per_s); break;

                case '\033':
                    choice = getchar();
                    choice = getchar();
                    switch(choice) {
                        case 'C': player_move_check1('d', fps, j2, j2_move_frame, j2_move, j2_effect, frames_per_s); break;
                        case 'D': player_move_check1('q', fps, j2, j2_move_frame, j2_move, j2_effect, frames_per_s); break;
                        default: break;
                    }
                    break;
                case 'l': player_move_check1('a', fps, j2, j2_move_frame, j2_move, j2_effect, frames_per_s); break;
                case 'm': player_move_check1('e', fps, j2, j2_move_frame, j2_move, j2_effect, frames_per_s); break;
                case 'o': player_move_check1('z', fps, j2, j2_move_frame, j2_move, j2_effect, frames_per_s); break;
                case 'p': player_move_check1('s', fps, j2, j2_move_frame, j2_move, j2_effect, frames_per_s); break;

                case ' ':
                    p = print_pause();
                    if(p == 2) return 2;
                    if(p == 3) return 3;
                    break;
                default: break;
            }
        }

        usleep(1000000 / frames_per_s);

        system(CLEAN_SCREEN);
        print_scene(grid, j1, j2);

        fps += 1;
        std::cout << "Image : " << fps << std::endl;
    }

    return 1;
}


/* Lancement du jeu */
void time_2_play(std::string scene, Joueur &j1, Joueur &j2, int frames_per_s) {
    int tmp = play(j1, j2, scene, frames_per_s);
    while(tmp != 1) {
        if(tmp == 2) {
            loading_bar();
            save_a_game(scene, j1, j2);
            system(CLEAN_SCREEN);
            print_first_line("Les données du jeu ont été sauvegardées !");
            return;
        } else if(tmp == 3) {
            system(CLEAN_SCREEN);
            start(frames_per_s);
        } else {
            j1.update_player();
            j2.update_player();
            j2.set_dir(1);
            tmp = play(j1, j2, scene, frames_per_s);
        }
    }
    std::vector<char> v = print_menu_endgame();
    char c = make_choice(v);
    if(c == '1') {
        j1.point_0();
        j2.point_0();
        time_2_play(scene, j1, j2, frames_per_s);
    } else {
        start(frames_per_s);
    }
}


/* Lancement du menu */
void start(int frames_per_s) {
    std::vector<char> choice = print_menu();

    if(choice[0] == '2') {
        std::string data = load_data_file();

        if(data == "") {
            print_first_line("Il n'y a pas de données de jeu...");
            text_center("Retour vers le menu.");
            std::cout << std::endl;
            loading_bar();
            start(frames_per_s);
            exit(0);
        } else {
            std::vector<std::string> res;
            std::string line = "";
            for(int i=0; i<data.length(); ++i) {
                if(data[i] != '\n') {
                    line += data[i];
                } else {
                    res.push_back(line);
                    line = "";
                }
            }

            std::vector<int> res_j1;
            std::vector<int> res_j2;
            std::string attri = "";
            for(int i=0; i<res[1].length(); ++i) {
                if(res[1][i] != ' ') {
                    attri += res[1][i];
                } else {
                    res_j1.push_back(stoi(attri));
                    attri = "";
                }
            }

            for(int i=0; i<res[2].length(); ++i) {
                if(res[2][i] != ' ') {
                    attri += res[2][i];
                } else {
                    res_j2.push_back(stoi(attri));
                    attri = "";
                }
            }
            
            Joueur j1 {res_j1[0], res_j1[1], res_j1[2], res_j1[3], res_j1[4]};
            Joueur j2 {res_j2[0], res_j2[1], res_j2[2], res_j2[3], res_j2[4]};

            time_2_play(res[0], j1, j2, frames_per_s);
        }
    } else if(choice[0] == '3') {
        exit(0);
    } else {
        // Chargement de la scène de combat
        std::string scene = "_____1_____2____";
        if(choice[1] == '3') {
            std::cout << "\r" << "Nom du fichier : ";
            std::string filename;
            std::cin >> filename;
            while(is_valid_scene(filename) != 0) {
                std::cout << "Mauvais fichier ! Donnez un bon chemin relatif : ";
                std::cin >> filename;
            }
            std::cout << filename << std::endl;
            scene = load_a_scene(filename);

            // loading_bar();
        } else if(choice[1] == '2') {
            print_first_line("Cliquez sur le bouton correspondant pour faire votre choix.");

            text_center("Scène du jeu :");
            std::cout << std::endl;

            text_center("1 - ________1_______x________2___");
            text_center("2 - ________1________________2___");
            std::cout << std::endl;

            separator();
            
            std::vector<char> v {'1', '2'};
            char c = make_choice(v);
            if(c == '1') {
                scene = "________1_______x________2___";
            } else {
                scene = "________1________________2___";
            }

            // loading_bar();
        }

        // Configutation des joueurs
        Joueur j1;
        Joueur j2;
        j2.set_dir(1);

        // Partie commencée
        time_2_play(scene, j1, j2, frames_per_s);
    }
}