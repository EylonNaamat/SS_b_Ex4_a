//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{
    class Duke : Player{
    private:

    public:
        Duke(){};
        ~Duke(){};
        bool income();
        bool foreign_aid();
        bool coup();
        std::string role();
        int coins();
    };
}