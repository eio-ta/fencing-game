#ifndef INTERRACTION_H
#define INTERACTION_H

#include <iostream>
#include <vector>

class Interaction {
    public:
        char make_choice(std::vector<char>);
        bool is_contains(std::vector<char>, char);

};

#endif // INTERACTION_H