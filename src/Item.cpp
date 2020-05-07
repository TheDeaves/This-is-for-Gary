#include "Item.hpp"

Item::Item(){
    this->name = "Test1";
    this->effectAmount = 10;
    this->itemType = "weapon";
    this->ilvl = 4;
}

Item::Item(string name, int effectAmount, string itemType){
    this->name = name;
    this->effectAmount = effectAmount;
    this->itemType = itemType;
    this->ilvl = 1;
}

string Item::getName(){
    return this->name;
}

int Item::getEffectAmount(){
    int temp = this->effectAmount * this->ilvl;

    return temp;
}

string Item::getItemType(){
    return this->itemType;
}

int Item::getilvl(){
    return this->ilvl;
}

void Item::setilvl(int amount){
    this->ilvl = amount;
}