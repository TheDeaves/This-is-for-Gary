#include "Character.hpp"

Character::Character()
{
    this->characterName = "Billy";
    this->maxHealth = 15;
    this->attack = 1;
    this->defense = 1;
    this->currentHealth = maxHealth;
    this->currentXP = 0;
    this->neededXP = 2;
    this->level = 1;
}

string Character::getCharacterName()
{
    return this->characterName;
}

int Character::getCurrentXP(){
    return this->currentXP;
}

void Character::setCharacterName(string userSetName)
{
    this->characterName = userSetName;
}

int Character::getGold()
{
    return this->gold;
}

void Character::healthMax()
{ //CURRENTLY HEAL AFTER EVERY FIGHT TO MAX
    this->currentHealth = maxHealth;
}

int Character::takeDamage(int amount)
{ //RETURNS CURRENTHEALTH AFTER DAMAGE FOR DEATH CHECK
    this->currentHealth -= amount;
    return this->currentHealth;
}

//Take Damage action using a passed in attack and defense
int Character::takeDamage(int attack, int defense)
{
    int amount = 0;
    int baseAmount = 3;            //Our base amount of damage is 3
    amount = (attack - defense) + baseAmount; //Our total amount of damage being dealt is the attack - the defense + the base amount
    if (amount < 0)
    { //If attack is negative. Use base amount.
        amount = baseAmount;
    }
    this->currentHealth -= amount; // Subtract the damage from the current health
    return amount; //Retun the amount of damage dealt for testing purposes
}

int Character::getCurrentHP()
{
    return this->currentHealth;
}

int Character::getDefense()
{
    return this->defense;
}

int Character::getAttack()
{
    return this->attack;
}

void Character::gainXP(int amount)
{
    this->currentXP = +amount;
}

bool Character::levelUp()
{  
    if (this->currentXP >= this->neededXP)
    {
        this->level = +1;                                           //CHANGES LEVEL
        this->neededXP = this->neededXP + (this->neededXP / 2) + 1; //CHANGES REQUIRED AMOUNT OF XP

        //UPGRADE PER LEVEL  WILL NEED TO SCALE IN FUTURE
        //MORE ATTRIBUTES IN FUTURE
        this->maxHealth = +3;
        this->attack = +1;  //added attack and defense
        this->defense = +1; //needs to scale better
        return true;
    }
    else
    {
        return false;
    }
}

void Character::gainGold(int amount)
{
    this->gold = +amount;
}