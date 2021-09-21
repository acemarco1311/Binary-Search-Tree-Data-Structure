#include "Node.h"
#include <iostream> 
#include <iomanip> 
#include <string>
#include <cmath> 
#include <vector>
#include <map>
using namespace std;


Node::Node(int key){ 
    this->key = key;
    this->parent = nullptr;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

Node::Node(int key, Node* parent, Node* left_child, Node* right_child){
    this->key = key;
    this->parent = parent;
    this->left_child = left_child;
    this->right_child = right_child;
}

Node::~Node(){

}

int Node::get_key(){
    return this->key;
}

Node* Node::get_parent(){
    return this->parent;
}

Node* Node::get_left_child(){ 
    return this->left_child;
}

Node* Node::get_right_child() {
    return this->right_child;
}

void Node::set_key(int new_key){
    this->key = new_key;
}

void Node::set_parent(Node* new_parent){
    this->parent = new_parent;
}

void Node::set_left_child(Node* new_left_child){
    this->left_child = new_left_child;
}

void Node::set_right_child(Node* new_right_child){ 
    this->right_child = new_right_child;
}

bool Node::is_leaf(){
    if(this->left_child == nullptr && this->right_child == nullptr){
        return true;
    }
    else return false;
}

bool Node::is_root(){
    if(this->parent == nullptr) return true;
    else return false;
}
