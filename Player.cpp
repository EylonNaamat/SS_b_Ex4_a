//
// Created by eylon on 4/26/22.
//
#include "Player.hpp"
#include "Game.hpp"
#include <stdexcept>

namespace coup{
    bool Player::income(){
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(this->num_coins >= 10){
            throw std::bad_exception("must coup!!!");
        }
        this->num_coins += 1;
        this->last_operation = "income";
        this->game->whose_turn();
        return true;
    }
    bool Player::foreign_aid(){
        if(this->is_blocked()){
            return false;
        }
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(this->num_coins >= 10){
            throw std::bad_exception("must coup!!!");
        }
        this->num_coins += 2;
        this->last_operation = "foreign_aid";
        this->game->whose_turn();
        return true;
    }
    std::string Player::role(){
        return "Player";
    }
    void Player::coup(Player& player){
        if(this->game->turn() != this->name){
            throw std::bad_exception("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(this->num_coins < 7){
            throw std::bad_exception("you dont have enough money!!!");
        }
        bool flag_eliminated = true;
        for(int i = 0; i < this->game->players.size(); ++i){
            if(this->game->players[i] == player.name){
                this->game->players[i] = "_" + player.name;
                flag_eliminated = false;
                break;
            }
        }
        if(flag_eliminated){
            throw std::bad_exception("player already eliminated!!!");
        }
        this->game->whose_turn();
        this->last_operation = "coup";
        this->num_coins -= 7;
    }
    int Player::coins(){
        return this->num_coins;
    }

    bool Player::is_blocked(){
        if(this->game->blocked == this->name)){
            return true;
        }
        return false;
    }
}