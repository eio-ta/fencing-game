#include "../include/menu.h"

Jeu jeu;

void Menu::print_loading_bar() {
    std::cout << std::endl << std::endl << "  LOADING : ";
    for(int i=0; i<5; ++i) {
        std::cout << "." << std::flush;
        sleep(1);
    }
    std::cout << " 100 %" << std::endl << std::endl;
    sleep(1);
    system(CLEAN_SCREEN);
}

void Menu::print_first_line_menu() {
    std::string str1 = "   Click on the corresponding button to make your choice.   ";
    std::cout << std::endl << std::endl << str1 << std::endl << std::endl;
    jeu.sc.print_separator();
}

int Menu::interaction_answer(std::vector<int> v) {
    jeu.sc.print_separator();
    std::cout << "Your answer : ";
    return jeu.inter.make_choice(v);
}

void Menu::print_first_menu() {
    Menu::print_first_line_menu();
    jeu.sc.print_text_center("MENU OF THE GAME");
    std::cout << std::endl;

    jeu.sc.print_text_center("1 - NEW GAME");
    jeu.sc.print_text_center("2 - LOAD THE LAST GAME");
    std::cout << std::endl;

    std::vector<int> v {49, 50};
    char choice = Menu::interaction_answer(v);

    system(CLEAN_SCREEN);
    if(choice == 49) Menu::print_second_menu(choice);
    else {
        // TODO : CHARGER UNE ANCIENNE PARTIE
    }
}

void Menu::print_second_menu(char choice1) {
    Menu::print_first_line_menu();
    jeu.sc.print_text_center("MENU OF THE GAME");
    std::cout << std::endl;

    jeu.sc.print_text_center("1 - ONE PLAYER");
    jeu.sc.print_text_center("2 - TWO PLAYER");
    jeu.sc.print_text_center("3 - BACK");
    std::cout << std::endl;

    std::vector<int> v {49, 50, 51};
    char choice2 = Menu::interaction_answer(v);

    system(CLEAN_SCREEN);
    if(choice2 == 51) Menu::print_first_menu();
    Menu::print_third_menu(choice1, choice2);
}

void Menu::print_third_menu(char choice1, char choice2) {
    Menu::print_first_line_menu();
    jeu.sc.print_text_center("MENU OF THE GAME");
    std::cout << std::endl;

    jeu.sc.print_text_center("1 - NEW SCENE");
    jeu.sc.print_text_center("2 - LOAD A SCENE FROM A FILE");
    jeu.sc.print_text_center("3 - BACK");
    std::cout << std::endl;

    std::vector<int> v {49, 50, 51};
    char choice3 = Menu::interaction_answer(v);

    if(choice3 == 49) {
        Menu::print_loading_bar();
        std::string scene = "_____1_____________2_____";

        jeu.sc.print_fight();

        jeu.start(scene, int(choice2));
        
        // TODO : FIN DU JEU
    } else if(choice3 == 50) {
        std::cout << "\r" << "The filename : ";
        std::string filename;
        std::cin >> filename;
        while(!jeu.sc.is_valid_scene(filename)) {
            std::cout << "Wrong filename ! Please, give a good filename : ";
            std::cin >> filename;
        }

        Menu::print_loading_bar();
        std::string scene = jeu.sc.load_a_scene(filename);

        jeu.sc.print_fight();

        jeu.start(scene, int(choice2));
        // TODO : FIN DU JEU
    } else {
        system(CLEAN_SCREEN);
        Menu::print_second_menu(choice2);
    };
}