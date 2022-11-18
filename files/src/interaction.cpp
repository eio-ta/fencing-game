#include "../include/interaction.h"

int Interaction::is_contains(std::vector<char> v, char e) {
    for(std::vector<char>::iterator it = v.begin() ; it != v.end(); ++it) {
        if(e == *it) return 0;
    }
    return 1;
}


char Interaction::make_choice(std::vector<char> v) {
    char choice;
    for(;;) {
        system("/bin/stty raw");
        choice = getchar();
        std::cout << "\b" << std::flush;
        system("/bin/stty cooked");
        if(Interaction::is_contains(v, choice) == 0) return choice;
    }
    return '0';
}