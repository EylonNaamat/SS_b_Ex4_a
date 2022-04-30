//
// Created by eylon on 4/26/22.
//
#include "Captain.hpp"
#include <stdexcept>
namespace coup{
    void Captain::steal(Player& player){
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(!is_in_the_game(player)){
            throw std::invalid_argument("the player not in the game!!!");
        }
        if(player.num_coins < 2){
            throw std::invalid_argument("player doesnt have enough coins!!!");
        }
        if(this->num_coins >= coup::Captain::max_coins){
            throw std::invalid_argument("must coup!!!");
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
        if(!is_in_the_game(player)){
            throw std::invalid_argument("the player not in the game!!!");
        }
        if(player.last_operation != "steal"){
            throw std::invalid_argument("cant block this operation!!!");
        }
        if(this->game->turn() == player.name){
            throw std::invalid_argument("cant block him its his turn!!!");
        }
        player.num_coins -= 2;
        player.stole_from->num_coins += 2;
        this->last_operation = "block";
    }

    std::string Captain::role(){
        return "Captain";
    }
}