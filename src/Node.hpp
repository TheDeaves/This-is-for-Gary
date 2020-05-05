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
void setValue(Item* payload);
Item* getValue();
private:
Item* payload;
Node* left;
Node* right;
};

#endif