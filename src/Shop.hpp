#ifndef SHOP_HPP
#define SHOP_HPP

#include "Item.hpp"

#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

class Shop{
    private: 
        Item shopInventory[20];

    public:
        Shop();
        void listItems();
};

#endif