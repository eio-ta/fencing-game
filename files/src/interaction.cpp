#include "../include/interaction.h"

int is_contains(std::vector<char> v, char e) {
    for(std::vector<char>::iterator it = v.begin() ; it != v.end(); ++it) {
        if(e == *it) return 0;
    }
    return 1;
}


char make_choice(std::vector<char> v) {
    char choice;
    while(1) {
        if(kbhit()) {
            choice = getchar();
            if(is_contains(v, choice) == 0) {
                return choice;
            }
        }
    }
    return '0';
}
