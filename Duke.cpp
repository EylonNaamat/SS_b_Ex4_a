//
// Created by eylon on 4/26/22.
//

#include "Duke.hpp"

namespace coup{
    void Duke::tax(){
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(this->num_coins >= 10){
            throw std::bad_exception("must coup!!!");
        }
        this->num_coins += 3;
        this->last_operation = "tax";
        this->game->whose_turn();
    }
    void Duke::block(Player& player){
        if(player.last_operation != "foreign_aid"){
            throw std::bad_exception("cant block this operation!!!");
        }
        player.num_coins -= 2;
        this->last_operation = "block";
    }
}