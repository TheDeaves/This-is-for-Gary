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

//string Tree::traverse(bool fool){
// 	return	this->recursiveTraverse(this->root, fool);		
//}

//string Tree::RecursiveTraverse(Node* subtreeRoot,bool fool2){
//	ostringstream os;

//	if(subtreeRoot == nullptr){
//		return "";
//	}

//	os << this->RecursiveTraverse(subtreeRoot->GetLeft(), fool2);

	//if(fool2){
	//	os << subtreeRoot->GetValue()->GetTitle() << ", by " << subtreeRoot->GetValue()->GetAuthor();
	//	os << "\n\tSubject: " << subtreeRoot->GetValue()->GetSubject();
	//	os <<"\n\tPublisher: " << subtreeRoot->GetValue()->GetPublisher();
	//	os <<"\n\t" << subtreeRoot->GetValue()->GetNumber_Available() << " " << subtreeRoot->GetValue()->GetFormat() << " copies available\n";
	//	
	//}
	//else{
	//	os << subtreeRoot->GetValue()->GetTitle() << endl;
	//}
	//	os << this->RecursiveTraverse(subtreeRoot->GetRight(), fool2);
//
//	return os.str();
//}


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
