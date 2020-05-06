#include "Node.hpp"

Node::Node(){

}

Node::Node(Item* b1){
	this->payload = b1;
	this->left = nullptr;
	this->right = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
}

Node* Node::getLeft(){
	return this->left;
}

void Node::setLeft(Node* left){
	this->left = left;
}

Node* Node::getRight(){
	return this->right;
}

void Node::setRight(Node* right){
	this->right = right;
}

void Node::setNext(Node* next){
    this->next = next;
}

Node* Node::getNext(){
    return this->next;
}

void Node::setPrev(Node* prev){
    this->prev = prev;
}

Node* Node::getPrev(){
    return this->prev;
}

void Node::setValue(Item* payload){
	this->payload = payload;
}

Item* Node::getValue(){
	return this->payload;
}