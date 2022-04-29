//
// Created by eylon on 4/26/22.
//
#include "Player.hpp"
#include "Game.hpp"
#include <stdexcept>

namespace coup{
    void Player::income(){
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(this->num_coins >= 10){
            throw std::invalid_argument("must coup!!!");
        }
        this->num_coins += 1;
        this->last_operation = "income";
        this->game->whose_turn();
    }
    void Player::foreign_aid(){
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(this->num_coins >= 10){
            throw std::invalid_argument("must coup!!!");
        }
        this->num_coins += 2;
        this->last_operation = "foreign_aid";
        this->game->whose_turn();
    }
    std::string Player::role(){
        return "Player";
    }
    void Player::coup(Player& player){
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(this->num_coins < 7){
            throw std::invalid_argument("you dont have enough money!!!");
        }
        bool flag_eliminated = true;
        for(int i = 0; i < this->game->curr_players[(uint)(i)].size(); ++i){
            if(this->game->curr_players[(uint)(i)] == player.name){
                this->game->curr_players[(uint)(i)].insert(0,"_");
                flag_eliminated = false;
                break;
            }
        }
        if(flag_eliminated){
            throw std::invalid_argument("player already eliminated!!!");
        }
        this->game->whose_turn();
        this->last_operation = "coup";
        this->num_coins -= 7;
    }
    int Player::coins(){
        return this->num_coins;
    }
}