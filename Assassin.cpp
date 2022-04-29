//
// Created by eylon on 4/26/22.
//
#include "Assassin.hpp"
#include <stdexcept>
#include <iostream>
namespace coup{

    void Assassin::coup(Player& player){
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(this->num_coins < 3){
            throw std::invalid_argument("dont have enough coins to coup!!!");
        }
        bool flag_eliminated = true;
        for(int i = 0; i < this->game->curr_players.size(); ++i){
            if(this->game->curr_players[(uint)(i)] == player.name){
                this->eliminated_player = player.name;
                std::cout << "check " << this->eliminated_player << std::endl;
                this->game->curr_players[(uint)(i)].insert(0,"_");
                flag_eliminated = false;
                break;
            }
        }
        if(flag_eliminated){
            throw std::invalid_argument("player already eliminated!!!");
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