#ifndef ITEM_HPP
#define ITEM_HPP

#include<iostream>

using namespace std;

class Item{
    public:
        Item();
        Item(string name, int effectAmount, string itemType);
        string getName();
        int getEffectAmount();
        string getItemType();
        int getilvl();
        void setilvl(int amount);

    private:
        string name;
        int effectAmount;
        string itemType;
        int ilvl;

};

#endif