//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>

namespace coup{
    class Ambassador : Player{
    public:
        Ambassador(coup::Game& game, std::string name) : Player(game, name){};
        ~Ambassador(){};
        void transfer(Player& player_a, Player& player_b);
        void block(Player& player);
    };
}
