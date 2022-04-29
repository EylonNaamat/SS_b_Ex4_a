//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>

namespace coup{
    class Contessa : Player{
    public:
        Contessa(coup::Game& game, std::string name): Player(game, name){};
        ~Contessa(){};
        void block(Player& player);
    };
}
