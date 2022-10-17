#ifndef POKEDEX.H
#define POKEDEX.H
#include <iostream>

using namespace std;

namespace jogo {
    class Personagens {
        public:
            int life, attack;

            int set_life(int l) {
                life = l;
                return life;
            }
            int get_life() {
                return life;
            }
            int life_damage(int ld) {
                life -= ld;
                return life;
            }

            int set_heal(int h) {
                life += h;
                return life;
            }
    };

    class Bulbasaur : public Personagens {
        public:
            int life = 150, attack = 20, heal = 20;
            string name = "Bulbasaur";
    };

    class Pikachu : public Personagens {
        public:
            int life = 100, attack = 30, heal = 10;
            string name = "Pikachu";
    };
}

#endif