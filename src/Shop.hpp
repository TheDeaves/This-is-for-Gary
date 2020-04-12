#ifndef SHOP_HPP
#define SHOP_HPP

#include "Item.hpp"

#include<fstream>
#include<sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <windows.h>

using namespace std;

class Shop{
    private: 
        Item shopInventory[20];

    public:
        Shop();
        void listItems();
        int randomNumberGen();// MOD NUMBER OF ITEMS IN ITEMS.TXT
        void displayItemForSale();

};

#endif