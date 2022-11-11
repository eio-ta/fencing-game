#include "../include/interaction.h"

int Interaction::is_contains(std::vector<int> v, int e) {
    for(std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it) {
        if(e == *it) return 0;
    }
    return 1;
}

char Interaction::make_choice(std::vector<int> v) {
    char choice;
    int key;
    for(;;) {
        system("/bin/stty raw");
        choice = getchar();
        std::cout << "\b" << std::flush;
        system("/bin/stty cooked");
        key = (int) choice;
        //std::cout << key << std::endl;
        if(Interaction::is_contains(v, key) == 0) return key;
    }
    return 0;
}