#include "DLL.hpp"

DLL::DLL(){
    this->head = nullptr;
}

void DLL::push(Item* item){
    Node* newnode = new Node(item);

    newnode->setNext(this->head);
    newnode->setPrev(nullptr);

    if(this->head != nullptr){
        head->setPrev(newnode);
    }

    this->head = newnode;
}

//Item* DLL::pop(){
//
//}

string DLL::displayList(){
    ostringstream temp;

    while(this->head != nullptr){
        temp << this->head->getValue()->getName() << "\n";
            this->head = this->head->getNext();
    }

    return temp.str();
}

Node* DLL::searchItemByName(string searchkey){
    Node* temp = this->head;
        while(temp != nullptr){
            if(temp->getValue()->getName() == searchkey){
                return temp;
            }
                temp = temp->getNext();
        }

    return nullptr;
}

Node* DLL::convertFromDLLtoTree(Node* node){
    Node* temp;
        temp->setValue(node->getValue());
        temp->setPrev(nullptr);
        temp->setNext(nullptr);

    delete node;

    return temp;
}