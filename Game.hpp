//
// Created by eylon on 4/26/22.
//
#include <vector>
#include <string>

namespace coup{
    class Game{
    public:
        std::vector<string> players;
        int turn;
    public:
        Game(){
            this->turn = 0;
        }
        ~Game(){};
        std::string turn();
        std::vector players();
        std::string winner();
        void whose_turn();
    };
}
