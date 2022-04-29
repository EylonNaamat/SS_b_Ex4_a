//
// Created by eylon on 4/26/22.
//
#include "Assassin.hpp"

namespace coup{

    void Assassin::coup(Player& player){
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(this->num_coins < 3){
            throw std::bad_exception("dont have enough coins to coup!!!");
        }
        bool flag_eliminated = true;
        for(int i = 0; i < this->game->players.size(); ++i){
            if(this->game->players[i] == player.name){
                this->eliminated_player = player.name;
                this->game->players[i].insert(0,"_");
                flag_eliminated = false;
                break;
            }
        }
        if(flag_eliminated){
            throw std::bad_exception("player already eliminated!!!");
        }
        this->game->whose_turn();
        if(this->num_coins >= 7){
            this->num_coins -= 7;
            this->last_operation = "coup";
        }else{
            this->num_coins -= 3;
            this->last_operation = "assassin_coup";
        }
    }
}