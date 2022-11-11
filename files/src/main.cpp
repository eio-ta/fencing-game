#include "../include/menu.h"

Menu m;

/* Main function : Start the game */
int main(int argc, char *argv[]) {
    m.print_loading_bar();
    m.print_first_menu();
    return 0;
}