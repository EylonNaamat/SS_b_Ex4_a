//
// Created by eylon on 4/26/22.
//
#include <vector>
#include "Player.hpp"
#include <string>

namespace coup{
    class Game{
    public:
        std::vector<Player> players;
        int turn;
    public:
        Game(){};
        ~Game(){};
        std::string turn();
        std::vector players();
        std::string winner();
    };
}
