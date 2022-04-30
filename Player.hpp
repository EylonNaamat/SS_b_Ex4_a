//
// Created by eylon on 4/26/22.
//
#include <string>
#include "Game.hpp"
#pragma once
namespace coup{
    class Player{
    public:
        std::string name;
        coup::Game* game;
        int num_coins;
        Player* stole_from;
        std::string eliminated_player;
        std::string last_operation;
        const static int max_coins = 10;
        const static int coup_coins = 7;
    public:
        Player(coup::Game& game, std::string name){
            this->name = name;
            this->game = &game;
            this->game->curr_players.push_back(name);
            this->num_coins = 0;
            this->eliminated_player = "";
            this->stole_from = NULL;
            this->last_operation = "";
        }
        virtual void income();
        virtual void foreign_aid();
        virtual void coup(Player& player);
        virtual std::string role();
        virtual int coins();
    };
}
