//
// Created by eylon on 4/26/22.
//
#include <string>
#include "Game.hpp"
namespace coup{
    class Player{
    protected:
        int state;
        std::string name;
        bool turn;
    public:
        Player(std::string name){
            this->int state = 0;
            this->name = name;
            this->turn = false;

        }
        virtual bool income();
        virtual bool foreign_aid();
        virtual bool coup();
        virtual std::string role();
        virtual int coins();

    };
}
