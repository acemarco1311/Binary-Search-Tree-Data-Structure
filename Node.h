#ifndef NODE_H 
#define NODE_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> 
#include <vector>
#include <map> 
using namespace std;

class Node{
    private: int key;
    private: Node* parent;
    private: Node* left_child;
    private: Node* right_child;

    public: Node(int key);
    public: Node(int key, Node* parent, Node* left_child, Node* right_child);
    public: ~Node();

    public: int get_key();
    public: Node* get_parent();
    public: Node* get_left_child();
    public: Node* get_right_child();

    public: void set_key(int new_key);
    public: void set_parent(Node* new_parent);
    public: void set_left_child(Node* new_left_child);
    public: void set_right_child(Node* new_right_child);

    public: bool is_leaf();
    public: bool is_root();
};





#endif
