#include "../include/interaction.h"

int Interaction::is_contains(std::vector<char> v, char e) {
    for(std::vector<char>::iterator it = v.begin() ; it != v.end(); ++it) {
        if(e == *it) return 0;
    }
    return 1;
}

char Interaction::make_choice(std::vector<char> v) {
    char key;
    for(;;) {
        system("/bin/stty raw");
        key = getchar();
        std::cout << "\b" << std::flush;
        system("/bin/stty cooked");
        if(Interaction::is_contains(v, key) == 0) return key;
    }
    return '0';
}