#ifndef NODE_HPP
#define NODE_HPP

#include "Item.hpp"
using namespace std;

class Node{
public:
Node();
Node(Item* item);
Node* getLeft();
void setLeft(Node* left);
Node* getRight();
void setRight(Node* right);
void setNext(Node* next);
Node* getNext();
void setPrev(Node* prev);
Node* getPrev();
void setValue(Item* payload);
Item* getValue();
private:
Item* payload;
Node* left;
Node* right;
Node* next;
Node* prev;
};

#endif