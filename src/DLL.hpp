#ifndef DLL_HPP
#define DLL_HPP

#include "Node.hpp"
#include "Item.hpp"

#include <string>
#include <sstream>

using namespace std;

class DLL{
    public:
        DLL();
        void push(Item* item);//INSERT AT HEAD
        Item* pop();//TAKE FROM HEAD AND DELETE
        string displayList();
        Node* searchItemByName(string searchkey);
    private:
        Node* head = nullptr;

};

#endif