#include "Character.hpp"

Character::Character(){
    this->characterName = "Billy";
    this->maxHealth = 10;
    this->currentHealth = maxHealth;
    this->currentXP = 0;
    this->neededXP = 15;
    this->level = 1;
}

string Character::getCharacterName(){
    return this->characterName;
}

void Character::setCharacterName(string userSetName){
    this->characterName = userSetName;
}