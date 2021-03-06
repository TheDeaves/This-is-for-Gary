#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include "../Item/Item.hpp"

#include <string>
#include <sstream>

using namespace std;

class Tree{
public:
Tree();
void insert(Item* book);
string recursiveTraverse(Node* subtreeRoot, bool fool2 = true);
string traverse(bool fool = true);
Node* search(string searchValue);
Node* recurseSearch(string searchValue, Node* subtreeRoot);
Node* getRoot();
Node* convertFromTreetoDLL(Node* node);
private:
Node* root;
Node* temp;
};

#endif