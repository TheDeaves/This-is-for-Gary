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
    int baseAmount = 3;            //Our base amount of damage is 3
    int amount = attack - defense; //Our amount of damage
    if (amount < 0)
    { //If attack is negative. Use base amount - the amount.
        amount = baseAmount - amount;
    }
    if (attack == defense) //If the same use base amount
    {
        amount = baseAmount;
    }
    else
    {                                             // If attack is greater then defense use that plus the base amount
        amount += baseAmount; // Add base damage to the attack - the defense
    }
    this->currentHealth -= amount; // Subtract the damage from the current health
    return this->currentHealth;
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