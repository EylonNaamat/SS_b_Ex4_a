//
// Created by eylon on 4/26/22.
//
#include <string>
#include "Game.hpp"
#include once
namespace coup{
    class Player{
    public:
        std::string name;
        coup::Game* game;
        int num_coins;
        Player* stole_from;
        std::string eliminated_player;
        std::string last_operation;
    public:
        Player(coup::Game& game, std::string name){
            this->name = name;
            this->game = &game;
            this->num_coins = 0;
            this->eliminated_player = "";
            this->stole_from = NULL;
            this->last_operation = "";
        }
        virtual bool income();
        virtual bool foreign_aid();
        virtual void coup(Player& player);
        virtual std::string role();
        virtual int coins();
        virtual bool is_blocked();
    };
}
