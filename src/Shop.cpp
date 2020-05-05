#include "Shop.hpp"

Shop::Shop(){
    ifstream items;
    string parseBySpace;
    string parseByLine;
    string itemAttributes[3];
    int i = 0;
    int j = 0;
    int temp;

    items.open("Texts/Items.txt");

        if(!items.is_open()){
            cout << "Items failed to load." << endl;
        }

    while(getline(items, parseByLine)){//BUG makes item name the entire line
        istringstream parseByLineStream(parseByLine);
            while(getline(parseByLineStream, parseBySpace, ',')){
                itemAttributes[i] = parseBySpace;
                    i++;
            }
            stringstream ss(itemAttributes[1]);
        ss >> temp;
        shopInventory.insert(new Item(itemAttributes[0], temp, itemAttributes[2]));
            i = 0;
                j++;
    }
     cout << shopInventory.traverse() << endl;
}

void Shop::listItems(){
    cout << shopInventory.traverse() << endl;
}

int Shop::randomNumberGen(){
    srand(rand());

    return rand() % 4;
}

void Shop::displayItemForSale(){
    cout << "ITEMS FOR SALE!!!" << endl;
 //   cout << "1. " << shopInventory[randomNumberGen()].getName() << " Cost: 50" << endl;
//    cout << "2. " << shopInventory[randomNumberGen()].getName() << " Cost: 50" << endl;
}