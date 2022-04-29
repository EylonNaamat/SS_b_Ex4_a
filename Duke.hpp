//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>

namespace coup{
    class Duke : Player{
    public:
        Duke(coup::Game& game, std::string name): Player(game, name){};
        ~Duke(){};
        void tax();
        void block(Player& player);
    };
}
