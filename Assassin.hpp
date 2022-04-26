//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{
    class Assassin : Player{
    private:

    public:
        Assassin(){};
        ~Assassin(){};
        bool income();
        bool foreign_aid();
        bool coup();
        std::string role();
        int coins();
    };
}
