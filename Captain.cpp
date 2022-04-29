//
// Created by eylon on 4/26/22.
//
#include "Captain.hpp"
namespace coup{
    void Captain::steal(Player& player){
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(player.num_coins < 2){
            throw std::bad_exception("player doesnt have enough coins!!!");
        }
        if(this->num_coins >= 10){
            throw std::bad_exception("must coup!!!");
        }
        this->num_coins += 2;
        player.num_coins -= 2;
        this->last_operation = "steal";
        this->stole_from = &player;
        this->game->whose_turn();
    }

    void Captain::block(Player& player){
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