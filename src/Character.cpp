#include "Character.hpp"

Character::Character(){
    this->characterName = "Billy";
    this->maxHealth = 15;
    this->currentHealth = maxHealth;
    this->currentXP = 0;
    this->neededXP = 2;
    this->level = 1;
}

string Character::getCharacterName(){
    return this->characterName;
}

void Character::setCharacterName(string userSetName){
    this->characterName = userSetName;
}

int Character::getGold(){
    return this->gold;
}

void Character::healthMax(){//CURRENTLY HEAL AFTER EVERY FIGHT TO MAX
    this->currentHealth = maxHealth;
}

int Character::takeDamage(int amount){//RETURNS CURRENTHEALTH AFTER DAMAGE FOR DEATH CHECK
    this->currentHealth -= amount;
        return this->currentHealth;
}

int Character::getCurrentHP(){
    return this->currentHealth;
}

void Character::gainXP(int amount){
    this->currentXP =+ amount;
}

bool Character::levelUp(){
    if(this->currentXP >= this->neededXP){
        this->level =+ 1;//CHANGES LEVEL
            this->neededXP = this->neededXP + (this->neededXP/2) + 1;//CHANGES REQUIRED AMOUNT OF XP

                //UPGRADE PER LEVEL  WILL NEED TO SCALE IN FUTURE
                //MORE ATTRIBUTES IN FUTURE
                this->maxHealth =+ 3;
                return true;
    }
    else{
        return false;
    }
}

void Character::gainGold(int amount){
    this->gold =+ amount;
}