//
// Created by eylon on 4/26/22.
//
#include <vector>
#include <string>
#pragma once
namespace coup{
    class Game{
    public:
        std::vector<std::string> curr_players;
        int player_turn;
    public:
        Game(){
            this->player_turn = 0;
        }
        ~Game(){};
        std::string turn();
        std::vector<std::string> players();
        std::string winner();
        void whose_turn();
    };
}
