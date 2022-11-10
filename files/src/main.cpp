#include <unistd.h>

#include "../include/menu.h"

Menu m;

/* Print the loading bar */
void print_loading_bar() {
    std::cout << std::endl << std::endl << "  LOADING : ";
    for(int i=0; i<10; ++i) {
        std::cout << "." << std::flush;
        sleep(1);
    }
    std::cout << " 100 %" << std::endl << std::endl;
    sleep(1);
    system(CLEAN_SCREEN);
}

/* Main function : Start the game */
int main(int argc, char *argv[]) {
    // print_loading_bar();
    m.print_first_line_menu();
    m.interaction_player();
    return 0;
}

    // // NEW BATTLE
    // // CHARGE BATTLE


    // // ONE PLAYER
    // // TWO PLAYER

    // // CHARGE THE SCENE
    // // RANDOM SCENE

    //     // for (int i=0; i<10; i++) {
    //     // std::cout << "i = " << i << std::endl;
    //     // sleep(1);
    //     // if (i == 5) {
    //     //     // Call the pause command
    //     //     clrscr();
    //     //     print_first_line_menu(str1);
    //     //     std::cout << (kbhit());
    //     // }