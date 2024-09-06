#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include "node.hpp"


template<typename T, size_t K = 2>
class Tree{

private:
Node<T>* root;     //pointer to the root Node of the tree



public:

//constructor
Tree() : root(nullptr){};


//destructor
~Tree(){
    if(root){
        delete root;
    }
}


//Add root to the tree
void add_root(Node<T>* rNode){
        
    //If the root already exists 
    if(root){              
        throw logic_error("The tree already has a root .");
    }

    root = rNode;
}


    //Return the root of the tree
Node<T>* get_root(){
    return root;
}


void add_sub_node(Node<T>* parent, Node<T>* child){
    
    if(!root){
        throw logic_error("There is no root for the tree .");
    }

    //check if it legal to add another child to parent Node
    if(parent->numOfCh() >= K){
        throw out_of_range("The parent Node already has the maximum number of childern.");
    }

    //Add the child to the parent children
    parent->addChild(child);
    
}















/*
Iterator& myHeap();

Iterator& begin_pre_order();

Iterator& end_pre_order();

Iterator& end_post_order();

Iterator& begin_post_order();

Iterator& end_in_order();

Iterator& begin_in_order();

Iterator& end_bfs_scan();

Iterator& begin_bfs_scan();

Iterator& end_dfs_scan();

Iterator& begin_dfs_scan();


*/

};


#endif
