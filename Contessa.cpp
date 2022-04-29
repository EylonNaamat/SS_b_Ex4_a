//
// Created by eylon on 4/26/22.
//
#include "Contessa.hpp"
#include <stdexcept>
#include <iostream>
namespace coup{
    void Contessa::block(Player& player){
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(player.last_operation != "assassin_coup"){
            throw std::invalid_argument("cant block this operation!!!");
        }
        bool flag_worked = false;
//        std::cout << this->game->curr_players.size() << std::endl;
        for(int i = 0; i < this->game->curr_players.size(); ++i){
            std::string tmp = this->game->curr_players[(uint)(i)];
            tmp.erase(0, 1);
            if(tmp == player.eliminated_player){
                this->game->curr_players[(uint)(i)] = player.eliminated_player;
                flag_worked = true;
            }
//            std::cout << "1." << player.eliminated_player << std::endl;
//            std::cout << "2." << tmp << std::endl;
//            std::cout << "3." << this->game->curr_players[(uint)(i)] << std::endl;
        }
        if(!flag_worked){
            throw std::invalid_argument("the eliminated player already back in the game!!!");
        }
    }
}