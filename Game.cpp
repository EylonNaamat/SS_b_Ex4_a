//
// Created by eylon on 4/26/22.
//
#include "Game.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace coup{
    std::string Game::turn(){
        return this->players[this->turn];
    }
    std::vector Game::players(){
        std::vector<string> curr_players;
        for(int i = 0; i < this->players.size(); ++i){
            if(this->players[i][0] != '_'){
                curr_players.push_back(this->players[i]);
            }
        }
        return curr_players;
    }
    std::string Game::winner(){
        int count = 0;
        int index_winner = 0;
        for(int i = 0; i < this->players.size(); ++i){
            if(this->players[i][0] != '_'){
                count++;
                index_winner = i;
            }
        }
        if(count != 1) {
            throw std::bad_exception("game is still on!!!");
        }
        return this->players[index_winner];
    }
    void Game::whose_turn(){
        this->turn = (this->turn+1)%this->players.size();
        while(this->players[this->turn][0] == '_'){
            this->turn = (this->turn+1)%this->players.size();
        }
    }
}