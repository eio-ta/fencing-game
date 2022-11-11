#ifndef INTERRACTION_H
#define INTERACTION_H

#include <iostream>
#include <vector>

class Interaction {
    public:
        char make_choice(std::vector<int>);
        int is_contains(std::vector<int>, int);
};

#endif // INTERACTION_H