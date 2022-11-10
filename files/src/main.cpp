#include <iostream>
#include <conio.h>
#include <string>

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
    clrscr();
}

/* Print the first line of the game */
void print_first_line_menu() {
    std::string str1 = "   Click on the corresponding button to make your choice.   ";
    std::string str2 = "";
    int size = str1.length();
    for(int i=0; i<size; ++i) {
        str2 += "_";
    }
    std::cout << std::endl << std::endl << str1 << std::endl << str2 << std::endl << std::endl;
}

/* Main function : Start the game */
int main(int argc, char *argv[]) {
    print_loading_bar();
    print_first_line_menu();
    
    m.interaction_player();


    // // Print the menu of the game
    // int max_c = str1.length();

    // std::string title = "MENU OF THE GAME";
    // std::cout << title << std::endl << std::endl;

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

    return 0;
}