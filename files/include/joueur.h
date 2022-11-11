#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur {
    public:
        int attribut = 3; // 1 = attack, 2 = block, 3 = rest
        int dir = 0; // 0 = right, 1 = left
        int point = 0;
};

class Humain: public Joueur {
    public:

};



// class Automate: public Joueur {

// };

#endif // JOUEUR_H