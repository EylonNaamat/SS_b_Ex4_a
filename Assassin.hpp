//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>
#pragma once

namespace coup{
    class Assassin : public Player{
    public:
        Assassin(coup::Game& game, std::string name): Player(game, name){};
        ~Assassin(){};
        void coup(Player& player);
    };
}
