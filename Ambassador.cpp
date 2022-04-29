//
// Created by eylon on 4/26/22.
//
#include "Ambassador.hpp"
namespace coup{
    void Ambassador::transfer(Player& player_a, Player& player_b){
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(player_a.game != player_b.game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(this->game != player_a.game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(this->num_coins >= 10){
            throw std::bad_exception("must coup!!!");
        }
        if(player_a.num_coins < 1){
            throw std::bad_exception("player a dont have enough money!!!");
        }
        player_a.num_coins -= 1;
        player_b.num_coins += 1;
        this->last_operation = "transfer";
        this->game->whose_turn();
    }

    void Ambassador::block(Player& player){
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(player.last_operation != "steal"){
            throw std::bad_exception("cant block this operation!!!");
        }
        player.num_coins -= 2;
        player.stole_from->num_coins += 2;
        this->last_operation = "block";
    }
}
