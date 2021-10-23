#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>
#include <iomanip>
#include <string> 
#include <cmath>
#include <vector>
#include <map>
using namespace std;

BinarySearchTree::BinarySearchTree(Node* root){
    this->root = root; 
    this->size = 1;
}

BinarySearchTree::BinarySearchTree(){
    this->root = nullptr;
    this->size = 0;
}

BinarySearchTree::~BinarySearchTree(){

}

Node* BinarySearchTree::get_root(){
    return this->root;
}

int BinarySearchTree::get_size(){
    return this->size; 
}

void BinarySearchTree::set_root(Node* new_root){ 
    this->root = new_root;
}

void BinarySearchTree::decrement_size(){
    if(this->size > 0){
        this->size--; 
    }
}

void BinarySearchTree::increment_size(){
    this->size++;
}

void BinarySearchTree::inorder_walk_down(Node* root){
    if(root != nullptr){
        inorder_walk_down(root->get_left_child());
        std::cout<<root->get_key()<<" " ;
        inorder_walk_down(root->get_right_child());
    }
}

Node* BinarySearchTree::get_min(Node* root){
    if(root->get_left_child() != nullptr) {
        root = root->get_left_child();
    }
    return root;
}

Node* BinarySearchTree::get_max(Node* root){
    if(root->get_right_child() != nullptr){
        root = root->get_right_child();
    }
    return root;
}

void BinarySearchTree::insert(Node* new_node){ 
    Node* temp = nullptr;
    Node* root = this->get_root();
    while (root != nullptr){
        temp = root;
        if (new_node->get_key() < root->get_key()){
            root = root->get_left_child();
        }
        else root = root->get_right_child();
    }
    new_node->set_parent(temp);
    if(temp == nullptr){ //if the tree is empty
        this->set_root(new_node);
        this->increment_size();
    }
    else if (new_node->get_key() < temp->get_key()){
        temp->set_left_child(new_node);
        this->increment_size();
    }
    else{ 
        temp->set_right_child(new_node);
        this->increment_size();
    }
}

Node* BinarySearchTree::search(Node* search_node){
    Node* current_node = this->get_root();
    while(current_node != nullptr){
        if(current_node->get_key() == search_node->get_key()){
            return current_node;
        }
        else if(search_node->get_key() < current_node->get_key()){
            current_node = current_node->get_left_child();
        }
        else current_node = current_node->get_right_child();
    }
    return current_node;
}

Node* BinarySearchTree::next_larger(Node* current_node){
    if(this->search(current_node) != nullptr){
        if(this->search(current_node)->get_right_child() != nullptr){
            return this->get_min(this->search(current_node)->get_right_child());
        }
        else{
            Node* temp = this->search(current_node)->get_parent();
            while (temp != nullptr && current_node == temp->get_right_child()){
                current_node = temp;
                temp = temp->get_parent();
            }
            return temp;
        }
    }
    return nullptr;
}

Node* BinarySearchTree::next_smaller (Node* current_node) {
    if(this->search(current_node) != nullptr){
        if(this->search(current_node)->get_left_child() != nullptr){
            return this->get_max(this->search(current_node)->get_left_child());
        }
        else{
            Node* temp = this->search(current_node)->get_parent();
            while(temp != nullptr && current_node == temp->get_left_child()){
                current_node = temp;
                temp = temp->get_parent();
            }
            return temp;
        }
    }
    return nullptr;
}

void BinarySearchTree::remove(Node* deleted_node){
    Node* actual_deleted_node; 
    if(deleted_node->get_left_child() == nullptr || deleted_node->get_right_child() == nullptr){
        actual_deleted_node = deleted_node;
    }
    else actual_deleted_node = this->next_larger(deleted_node);
    Node* actual_deleted_node_child;
    if(actual_deleted_node->get_left_child() != nullptr){
        actual_deleted_node_child = actual_deleted_node->get_left_child();
    }
    else actual_deleted_node_child = actual_deleted_node->get_right_child(); 
    if(actual_deleted_node_child != nullptr){
        actual_deleted_node_child->set_parent(actual_deleted_node->get_parent());
    }
    if (actual_deleted_node->get_parent() == nullptr){
        this->set_root(actual_deleted_node_child);
    }
    else if(actual_deleted_node == actual_deleted_node->get_parent()->get_left_child()){
        actual_deleted_node->get_parent()->set_left_child(actual_deleted_node_child);
    }
    else actual_deleted_node->get_parent()->set_right_child(actual_deleted_node_child);
    if(actual_deleted_node->get_key() != deleted_node->get_key()){                 
        deleted_node->set_key(actual_deleted_node->get_key());                     
        if (actual_deleted_node->get_left_child() != nullptr){                     
            deleted_node->set_left_child(actual_deleted_node->get_left_child());   
        }                                                                          
        if (actual_deleted_node->get_right_child() != nullptr) {                   
            deleted_node->set_right_child(actual_deleted_node->get_right_child()); 
        }                                                                          
    }                                                                              
    actual_deleted_node->set_parent(nullptr);
    actual_deleted_node->set_left_child(nullptr);
    actual_deleted_node->set_right_child(nullptr);
    this->decrement_size();
    return;
}

int main(){
    Node* root = new Node(10);
    BinarySearchTree* tree = new BinarySearchTree(root);
    Node* one = new Node(8);
    Node* two = new Node(12);
    Node* three = new Node(15);
    Node* four = new Node(9);
    tree->insert(one);
    tree->insert(two);
    tree->insert(three);
    tree->inorder_walk_down(root);
    std::cout << endl;
    std::cout<<"Next larger of 8: " << tree->next_larger(one)->get_key() <<endl;
    std::cout<< "Next larger of 12 is: " << tree->next_larger(two)->get_key() << endl;
    std::cout<< "Next smaller of 12 is: " << tree->next_smaller(two)->get_key() << endl;
    tree->insert(four);
    std::cout<<"Removing 8 out of the Binary Search Tree ... " <<endl;
    tree->remove(one);
    std::cout<<"The tree after removing 8: " << endl;
    tree->inorder_walk_down(root);
    return 0;
}
