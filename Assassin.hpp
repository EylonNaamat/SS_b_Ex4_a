//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>

namespace coup{
    class Assassin : Player{
    public:
        Assassin(coup::Game& game, std::string name): Player(gamem, name){};
        ~Assassin(){};
        void coup(Player& player);
    };
}
