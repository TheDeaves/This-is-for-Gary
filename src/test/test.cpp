#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../Character.hpp"
#include "../Dialogue.hpp"
#include "../Combat.hpp"

using namespace std;

TEST_CASE("Character Class")
{
    Character c;
    c.setCharacterName("HELLO");
        REQUIRE(c.getCharacterName() == "HELLO");
}

TEST_CASE("Dialogue Class")
{

}

TEST_CASE("Combat Class")
{


}