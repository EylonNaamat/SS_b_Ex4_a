//
// Created by eylon on 4/30/22.
//

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "doctest.h"
#include <iostream>

using namespace coup;

TEST_CASE("Game functions - good"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    CHECK(game_1.turn() == "Moshe");
    duke.income();
    CHECK(game_1.turn() == "Yossi");
    assassin.income();
    CHECK(game_1.turn() == "Meirav");
    ambassador.income();
    CHECK(game_1.turn() == "Reut");
    captain.income();
    CHECK(game_1.turn() == "Gilad");
    contessa.income();

    std::vector<std::string> players = game_1.players();

    bool flag = false;
    for(std::string name : players){
        if(name != "Moshe" && name != "Yossi" && name != "Meirav" && name != "Reut" && name != "Gilad"){
            flag = true;
        }
    }
    CHECK(flag == false);

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.coup(assassin);
    ambassador.coup(captain);
    contessa.coup(duke);

    ambassador.foreign_aid();
    contessa.foreign_aid();
    ambassador.foreign_aid();
    contessa.foreign_aid();
    ambassador.foreign_aid();
    contessa.foreign_aid();
    ambassador.foreign_aid();
    contessa.foreign_aid();
    ambassador.coup(contessa);
    CHECK(game_1.winner() == "Meirav");
}

TEST_CASE("Game functions - bad"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    CHECK_FALSE(game_1.turn() == "Yossi");
    CHECK_FALSE(game_1.turn() == "Meirav");
    CHECK_FALSE(game_1.turn() == "Reut");
    CHECK_FALSE(game_1.turn() == "Gilad");

    CHECK_THROWS(game_1.winner());
}

TEST_CASE("Player functions - good"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    duke.income();
    assassin.income();
    ambassador.income();
    captain.income();
    contessa.income();

    std::vector<std::string> players = game_1.players();

    CHECK(duke.num_coins == 1);
    CHECK(assassin.num_coins == 1);
    CHECK(ambassador.num_coins == 1);
    CHECK(captain.num_coins == 1);
    CHECK(contessa.num_coins == 1);

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    CHECK(duke.coins() == 3);
    CHECK(assassin.coins() == 3);
    CHECK(ambassador.coins() == 3);
    CHECK(captain.coins() == 3);
    CHECK(contessa.coins() == 3);

    CHECK(duke.role() == "Duke");
    CHECK(assassin.role() == "Assassin");
    CHECK(ambassador.role() == "Ambassador");
    CHECK(captain.role() == "Captain");
    CHECK(contessa.role() == "Contessa");

}

TEST_CASE("Player functions - bad"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    Game game_2{};
    Duke eylon{game_2, "Eylon"};

    // its dukes turn
    CHECK_THROWS(assassin.foreign_aid());
    CHECK_THROWS(ambassador.foreign_aid());
    CHECK_THROWS(captain.foreign_aid());
    CHECK_THROWS(contessa.foreign_aid());

    // every one has 2 coins
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    // every one has 4 coins
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    // every one has 6 coins
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    // every one has 8 coins
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    //everyone must coup have more than 7 coins
    CHECK_THROWS(duke.foreign_aid());
    CHECK_THROWS(assassin.foreign_aid());
    CHECK_THROWS(ambassador.foreign_aid());
    CHECK_THROWS(captain.foreign_aid());
    CHECK_THROWS(contessa.foreign_aid());

    duke.coup(assassin);
    // assassin not in the game anymore
    CHECK_THROWS(assassin.coup(ambassador));
    //ambassador and eylon arent in the same game
    CHECK_THROWS(ambassador.coup(eylon));
    ambassador.coup(captain);
    contessa.coup(duke);

    // ambassador dont have enough money
    CHECK_THROWS(ambassador.coup(contessa));

    ambassador.foreign_aid();
    contessa.foreign_aid();
    ambassador.foreign_aid();
    contessa.foreign_aid();
    ambassador.foreign_aid();
    contessa.foreign_aid();
    ambassador.coup(contessa);
}

TEST_CASE("Ambassador functions - good"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.income();
    assassin.income();
    CHECK(duke.coins() == 3);
    CHECK(captain.coins() == 2);
    ambassador.transfer(duke, captain);
    CHECK(duke.coins() == 2);
    CHECK(captain.coins() == 3);

    captain.steal(assassin);
    CHECK(captain.coins() == 5);
    ambassador.block(captain);
    CHECK(captain.coins() == 3);
}

TEST_CASE("Ambassador functions - bad"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    Game game_2{};
    Ambassador eylon{game_2, "eylon"};
    eylon.foreign_aid();
    eylon.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    //captain dont have money, hence cant transfer
    CHECK_THROWS(ambassador.transfer(captain,duke));
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    // its not ambassadors turn
    CHECK_THROWS(ambassador.transfer(duke, assassin));
    assassin.foreign_aid();
    //eylon and duke arent in the same game
    CHECK_THROWS(ambassador.transfer(eylon,duke));
    //eylon and the players arent in  the same game
    CHECK_THROWS(eylon.transfer(duke,captain));

    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.coup(assassin);
    // ambassador must coup
//    std::cout << ambassador.coins() <<std::endl;
    CHECK_THROWS(ambassador.transfer(duke, captain));
    ambassador.coup(duke);
    captain.coup(contessa);
}

TEST_CASE("Assassin functions - good") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.coup(duke);
    CHECK(assassin.coins() == 1);

    std::vector<std::string> players = game_1.players();
    bool is_in = false;
    for(std::string name : players){
        if(name == "Moshe"){
            is_in = true;
        }
    }
    CHECK(is_in == false);
}

TEST_CASE("Assassin functions - bad") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    Game game_2{};
    Assassin eylon{game_2, "eylon"};
    eylon.foreign_aid();
    eylon.foreign_aid();

    duke.foreign_aid();
    //assassin dont have enough money to coup
    CHECK_THROWS(assassin.coup(duke));
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    //its dukes turn
    CHECK_THROWS(assassin.coup(duke));
    duke.foreign_aid();
    //eylon and assassin arent in the same game
    CHECK_THROWS(assassin.coup(eylon));
    assassin.coup(duke);
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();


    //duke already eliminated
    CHECK_THROWS(assassin.coup(duke));
}

TEST_CASE("Captain functions - good") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    Captain captain2{game_1, "Eylon"};

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    captain2.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    CHECK(duke.coins() == 4);
    CHECK(captain.coins() == 2);
    captain.steal(duke);
    CHECK(duke.coins() == 2);
    CHECK(captain.coins() == 4);
    contessa.foreign_aid();
    captain2.block(captain);
    CHECK(duke.coins() == 4);
    CHECK(captain.coins() == 2);
}

TEST_CASE("Captain functions - bad") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    Captain captain2{game_1, "Eylon"};

    Game game_2{};
    Captain naamat{game_2, "Naamat"};

    duke.foreign_aid();
    assassin.foreign_aid();
    //its not captain turn
    CHECK_THROWS(captain.steal(duke));
    ambassador.foreign_aid();
    //naamat and captain arent in the same game
    CHECK_THROWS(captain.steal(naamat));
    //contessa dont have enough money, therefore cant steal from her
    CHECK_THROWS(captain.steal(contessa));
    captain.foreign_aid();
    contessa.foreign_aid();
    //naamat and captain2 arent in the same cant
    CHECK_THROWS(captain2.block(naamat));
    captain2.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    captain2.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    captain2.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    //cant block non steal play
    CHECK_THROWS(captain2.block(captain));
    captain2.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    captain2.foreign_aid();

    duke.coup(assassin);
    ambassador.coup(contessa);
    //cant steal must coup
    CHECK_THROWS(captain.steal(captain2));
}

TEST_CASE("Contessa functions - good") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();

    std::vector<std::string> players = game_1.players();
    bool is_in = false;
    for(std::string name : players){
        if(name == "Moshe"){
            is_in = true;
        }
    }
    assassin.coup(duke);
    players = game_1.players();
    is_in = false;
    for(std::string name : players){
        if(name == "Moshe"){
            is_in = true;
        }
    }
    CHECK(is_in == false);
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.block(assassin);
    players = game_1.players();
    is_in = false;
    for(std::string name : players){
        if(name == "Moshe"){
            is_in = true;
        }
    }
    CHECK(is_in == true);
}

TEST_CASE("Contessa functions - bad") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    Game game_2{};
    Contessa naamat{game_2, "Naamat"};

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    //contessa cant block player that not in the game
    CHECK_THROWS(contessa.block(naamat));
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    //can block only assassin coup act
    CHECK_THROWS(contessa.block(assassin));
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    duke.income();
    assassin.coup(duke);
    CHECK(assassin.last_operation == "coup");
    //contessa cant block a regular coup
    CHECK_THROWS(contessa.block(assassin));

    ambassador.income();
    captain.income();
    contessa.income();

    assassin.foreign_aid();
    ambassador.income();
    captain.income();
    contessa.income();

    //cant eliminate a player that already been eliminated
    CHECK_THROWS(assassin.coup(duke));
    assassin.coup(ambassador);
}

TEST_CASE("Duke functions - good") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    duke.tax();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    CHECK(duke.coins() == 3);

    CHECK(contessa.coins() == 2);
    duke.block(contessa);
    CHECK(contessa.coins() == 0);
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
}

TEST_CASE("Duke functions - bad") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};

    Game game_2{};
    Duke naamat{game_2, "Naamat"};
    naamat.foreign_aid();

    duke.tax();
    //cant vlock a player not in the game
    CHECK_THROWS(duke.block(naamat));
    assassin.income();
    ambassador.income();
    captain.income();
    //cant make tax when not your turn
    CHECK_THROWS(duke.tax());
    contessa.income();

    //cant block a play which is not foreign_aid
    CHECK_THROWS(duke.block(contessa));
    duke.tax();
    assassin.income();
    ambassador.income();
    captain.income();
    contessa.income();

    duke.tax();
    assassin.income();
    ambassador.income();
    captain.income();
    contessa.income();

    duke.tax();
    assassin.income();
    ambassador.income();
    captain.income();
    contessa.income();

    //cant get tax when have more than 10 coins, must coup
    CHECK_THROWS(duke.tax());
}




