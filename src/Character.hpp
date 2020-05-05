#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Item.hpp"
#include "Node.hpp"
#include "Tree.hpp"

#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class Character{
    private:
        string characterName;
        int maxHealth;
        int currentHealth;
        int currentXP;
        int level;
        int neededXP;
        int gold;
        int attack;
        int defense;
        int currentStoryPosForLoad;

    public:
        Character();
      //  Character(string getCharacterName, int maxHealth, int currentHealth, int currentXP, int level, int)
        void setCharacterName(string userSetName);
        int getCurrentXP();
        string getCharacterName();
        int getGold();
        int getCurrentStoryPosForLoad();
        void setAttack(int amount);

        //COMBAT
        void healthMax();//CURRENTLY HEAL AFTER EVERY FIGHT TO MAX
        int takeDamage(int amount);//RETURNS CURRENTHEALTH AFTER DAMAGE FOR DEATH CHECK
        int takeDamage(int attack, int defense);
        int getCurrentHP();
        int getAttack();
        int getDefense();
        void gainXP(int amount);
        bool levelUp();//LEVELS UP ATTRIBUTES
        void gainGold(int amount);

        //SAVING AND LOADING
        bool Save(int currentStoryPos);
        void Load();
};

#endif