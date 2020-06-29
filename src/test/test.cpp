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
#include "../DLL.hpp"

using namespace std;

TEST_CASE("Character Class")
{
    Character c;//PLAYER
    Character e;//ENEMY

    c.setCharacterName("HELLO");
        REQUIRE(c.getCharacterName() == "HELLO");

        REQUIRE(c.getCurrentHP() == 15);

    c.takeDamage(3);

        REQUIRE(c.getCurrentHP() == 12);

    c.takeItemToINV(new Item("Axe", 500, "weapon"));
    c.takeItemToINV(new Item("ChestArmor", 1000, "armor"));
    c.takeItemToINV(new Item("Sword", 250, "weapon"));

        REQUIRE(c.displayCharacterINV() == "Sword\nChestArmor\nAxe\n");

    c.giveItemFromINV("ChestArmor");

        REQUIRE(c.displayCharacterINV() == "Axe\nSword\n");
    
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
    Character p;//PLAYER
    Character e;//ENEMY

        REQUIRE(c.getTurn() == 0);

    c.increTurn();
    c.increTurn();
    c.increTurn();
    c.increTurn();
    c.increTurn();

        REQUIRE(c.getTurn() == 5);

        REQUIRE(c.blockCheck(1,1));

        REQUIRE(!c.blockCheck(1,3));

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

    string searchTerm = "Axe";

    Node* temp = itemList.search(searchTerm);

    REQUIRE(temp->getValue()->getName() == searchTerm);


}

TEST_CASE("DLL Class"){
    DLL dll;

    dll.push(new Item("Axe", 500, "weapon"));
    dll.push(new Item("ChestArmor", 1000, "armor"));
    dll.push(new Item("Sword", 250, "weapon"));

    REQUIRE(dll.searchItemByName("Axe")->getValue()->getName() == "Axe");

    REQUIRE(dll.searchItemByName("Macaroni") == nullptr);

    

}