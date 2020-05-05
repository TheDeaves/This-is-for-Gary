#include "tree.hpp"

#include <iostream>

Tree::Tree(){
	this->root = nullptr;
}

void Tree::insert(Item* item){
	Node* newNode = new Node(item);

	if(this->root == nullptr){
		this->root = newNode;
			return;
	}

	Node* currentNode = this->root;
	while(currentNode != nullptr){

		if(currentNode->getValue()->getName() > newNode->getValue()->getName()){
			if(currentNode->getLeft() == nullptr){
				currentNode->setLeft(newNode);
					break;
			}
		currentNode = currentNode->getLeft();
		}
		else{
			if(currentNode->getRight() == nullptr){
				currentNode->setRight(newNode);
					break;
			}
		currentNode = currentNode->getRight();
		}
	}
}

string Tree::traverse(bool fool){
	return	this->recursiveTraverse(this->root, fool);		
}

string Tree::recursiveTraverse(Node* subtreeRoot,bool fool2){
	ostringstream os;

	if(subtreeRoot == nullptr){
		return "";
	}

	os << this->recursiveTraverse(subtreeRoot->getLeft(), fool2);

	if(fool2){
		os << "Name of Item: " << subtreeRoot->getValue()->getName() << "\n";
		os << "Item effect: " << subtreeRoot->getValue()->getEffectAmount() << "\n";
		os << "Item type: " << subtreeRoot->getValue()->getItemType() << "\n";
		
	}
	else{
		os << subtreeRoot->getValue()->getName() << endl;
	}
		os << this->recursiveTraverse(subtreeRoot->getRight(), fool2);

	return os.str();
}


//Node* Tree::search(string searchValue){
//	return this->recurseSearch(searchValue, this->root);
//}


//Node* Tree::recurseSearch(string searchValue, Node* subtreeRoot){
//
//	if(subtreeRoot == nullptr){
//		this->temp = nullptr;
//		return this->temp;
//	}
//	if(subtreeRoot->getValue()->getName() == searchValue){
//		this->temp = subtreeRoot;
//		return subtreeRoot;
//	}
//		if(subtreeRoot->getLeft() != nullptr || subtreeRoot->getRight() != nullptr){
//			if(subtreeRoot->getRight() != nullptr){	
//				return this->temp = this->RecurseSearch(searchValue, subtreeRoot->getRight());
//			}
//			else if(subtreeRoot->getLeft() != nullptr){
//				return this->temp = this->RecurseSearch(searchValue, subtreeRoot->getLeft());
//			}
//		}
//	return nullptr;
//}

Node* Tree::getRoot(){
	return this->root;
}
