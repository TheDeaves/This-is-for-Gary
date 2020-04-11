#include "Item.hpp"

Item::Item(){
    this->name = "Test1";
    this->effectAmount = 10;
    this->itemType = "weapon";
}

Item::Item(string name, int effectAmount, string itemType){
    this->name = name;
    this->effectAmount = effectAmount;
    this->itemType = itemType;
}

string Item::getName(){
    return this->name;
}

int Item::getEffectAmount(){
    return this->effectAmount;
}

string Item::getItemType(){
    return this->itemType;
}