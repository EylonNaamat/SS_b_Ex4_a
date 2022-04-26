//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{
    class Captain : Player{
    private:

    public:
        Captain(){};
        ~Captain(){};
        bool income();
        bool foreign_aid();
        bool coup();
        std::string role();
        int coins();
    };
}
