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

    while(getline(items, parseByLine)){
        istringstream parseByLineStream(parseByLine);
            while(getline(parseByLineStream, parseBySpace)){
                itemAttributes[i] = parseBySpace;
                    i++;
            }
            stringstream ss(itemAttributes[1]);
        ss >> temp;
        shopInventory[j]= Item(itemAttributes[0], temp, itemAttributes[2]);

            i = 0;
                j++;
    }
     
}

void Shop::listItems(){
    for(int i = 0; i < 1; i++){
        cout << shopInventory[i].getName() << endl;
    }
}