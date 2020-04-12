#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../Character.hpp"
#include "../Dialogue.hpp"
#include "../Combat.hpp"
#include "../Item.hpp"

using namespace std;

TEST_CASE("Character Class")
{
    Character c;
    c.setCharacterName("HELLO");
        REQUIRE(c.getCharacterName() == "HELLO");

        REQUIRE(c.getCurrentHP() == 15);

    c.takeDamage(3);

        REQUIRE(c.getCurrentHP() == 12);
}

TEST_CASE("Dialogue Class")
{
    Dialogue d;

        REQUIRE(d.getWelcome() == "A dirty man walks out beside you into the desert coliseum and he quickly asks your name...");

        REQUIRE(d.getInGameDay() == 0);

    d.incrementInGameDay();
    d.incrementInGameDay();
    d.incrementInGameDay();

        REQUIRE(d.getInGameDay() == 3);
}

TEST_CASE("Combat Class")
{
    Combat c;

        REQUIRE(c.getTurn() == 0);

    c.increTurn();
    c.increTurn();
    c.increTurn();
    c.increTurn();
    c.increTurn();

        REQUIRE(c.getTurn() == 5);

}

TEST_CASE("Item Class"){
    Item i("Item1", 10, "weapon");

        REQUIRE(i.getName() == "Item1");
}