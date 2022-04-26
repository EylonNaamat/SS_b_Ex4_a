//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup{
    class Ambassador : Player{
    private:
        coup::Player player;
    public:
        Ambassador(coup::Game &game, std::string name){
            game.players.push_back(this);
            Player{name};

        };
        ~Ambassador(){};
        bool income();
        bool foreign_aid();
        bool coup();
        std::string role();
        int coins();
    };
}
