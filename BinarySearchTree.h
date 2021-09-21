#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"
#include <iostream> 
#include <iomanip>
#include <string>
#include <cmath> 
#include <vector> 
#include <map> 
using namespace std;

class BinarySearchTree{
    private: Node* root;
    private: int size;

    public: BinarySearchTree(Node* root);
    public: BinarySearchTree();
    public: ~BinarySearchTree();

    public: Node* get_root();
    public: int get_size();

    public: void set_root(Node* new_root);
    public: void decrement_size();
    public: void increment_size();

    public: void insert(Node* new_node);
    public: void remove(Node* deleted_node);
    public: Node* search(Node* search_node);
    public: Node* get_max(Node* root);
    public: Node* get_min(Node* root);
    public: Node* next_larger(Node* current_node);
    public: Node* next_smaller(Node* current_node);
    public: void inorder_walk_down(Node* root);
    
};




#endif
