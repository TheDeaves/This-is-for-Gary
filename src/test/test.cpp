#define CATCH_CONFIG_MAIN

#include<sstream>
#include<iostream>

#include "catch/catch.hpp"
#include "../Character.hpp"
#include "../Dialogue.hpp"
#include "../Combat.hpp"
#include "../Item.hpp"
#include "../Shop.hpp"
#include "../Node.hpp"
#include "../Tree.hpp"

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

TEST_CASE("Shop Class"){

}

TEST_CASE("Node Class"){
    Item item;
    Item *itemPTR = &item;
    Node n1(itemPTR);

    REQUIRE(n1.getValue()->getName() == item.getName());

}

TEST_CASE("Tree Class"){
    Tree itemList;

    itemList.insert(new Item("Axe", 500, "weapon"));
    itemList.insert(new Item("ChestArmor", 1000, "armor"));
    itemList.insert(new Item("Sword", 250, "weapon"));

    const string traversedTree = "Name of Item: Axe\n"
                                "Item effect: 500\n"
                                "Item type: weapon\n"
                                "Name of Item: ChestArmor\n"
                                "Item effect: 1000\n"
                                "Item type: armor\n"
                                "Name of Item: Sword\n"
                                "Item effect: 250\n"
                                "Item type: weapon\n";

    REQUIRE(traversedTree == itemList.traverse());


}