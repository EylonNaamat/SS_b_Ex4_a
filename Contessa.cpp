//
// Created by eylon on 4/26/22.
//
#include "Contessa.hpp"
namespace coup{
    void Contessa::block(Player& player){
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(player.last_operation != "assassin_coup"){
            throw std::bad_exception("cant block this operation!!!");
        }
        bool flag_worked = false;
        for(int i = 0; this->game->players.size(); ++i){
            if(this->game->players[i].erase(0,1) == player.eliminated_player){
                this->game->players[i] = player.eliminated_player;
                flag_worked = true;
            }
        }
        if(!flag_worked){
            throw std::bad_exception("the eliminated player already back in the game!!!");
        }
    }
}