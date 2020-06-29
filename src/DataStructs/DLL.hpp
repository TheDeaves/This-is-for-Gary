#ifndef DLL_HPP
#define DLL_HPP

#include "Node.hpp"
#include "../Item/Item.hpp"

#include <string>
#include <sstream>

using namespace std;

class DLL{
    public:
        DLL();
        void push(Item* item);//INSERT AT HEAD
       // Item* pop();//TAKE FROM HEAD AND DELETE
        string displayList();
        Node* searchItemByName(string searchkey);
        Node* convertFromDLLtoTree(Node* node);
    private:
        Node* head = nullptr;

};

#endif