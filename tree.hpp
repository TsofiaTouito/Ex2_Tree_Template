#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include "Iterator.hpp"
#include "node.hpp"

using namespace std;

template<typename T, size_t K = 2>
class Tree{

private:
Node<T>* root;     //pointer to the root Node of the tree



public:

//constructors
Tree() : root(nullptr){};


//destructor
void delete_sub_tree(Node<T>* node) {
    if (!node) return;
    for (Node<T>* child : node->getChildren()) {
        delete_sub_tree(child);
    }
    delete node;
}


~Tree() {
    delete_sub_tree(root);
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
*/

PreOrderIterator<T> begin_pre_order() const {

    if constexpr(K != 2) {  //For a general tree (Not a binery treee) return DFS traversal
        return DfsIterator<T>(root);
    }
    else{
        return PreOrderIterator<T>(root);  // For binary tree (K==2)
    }

}

PreOrderIterator<T> end_pre_order() const{
    
    if constexpr(K != 2){  //For a general tree (Not a binery treee) return DFS traversal
        return DfsIterator<T>(nullptr);
    }
    else{
        return PreOrderIterator<T>(nullptr);
    }
}


//-----------------------------------------------------------------


auto begin_post_order() const {
    
    if constexpr(K != 2){   //For a general tree (Not a binery treee) return DFS traversal
        return DfsIterator<T>(root);
    }
    else{
        return PostOrderIterator<T>(root);
    }
}

auto end_post_order() const {
    
    if constexpr(K != 2){   //For a general tree (Not a binery treee) return DFS traversal
        return DfsIterator<T>(nullptr);
    }
    else {    
        return PostOrderIterator<T>(nullptr);
    }
}


//-----------------------------------------------------------------


auto begin_in_order() const {
    
    if constexpr(K != 2){  //For a general tree (Not a binery treee) return DFS traversal
        return DfsIterator<T>(root);
    }
    else{
        return InOrderIterator<T>(root);
    }
}

auto end_in_order() const {
    
    if constexpr(K != 2){  //For a general tree (Not a binery treee) return DFS traversal
        return DfsIterator<T>(nullptr);
    }
    else{
        return InOrderIterator<T>(nullptr);
    }

}
//-----------------------------------------------------------------


BfsIterator<T> begin_bfs_scan() const {
    return BfsIterator<T>(root);
}

BfsIterator<T> end_bfs_scan() const {
    return BfsIterator<T>(nullptr);

}


//------------------------------------------------------------------


DfsIterator<T> begin_dfs_scan() const {
    return DfsIterator<T>(root);
}

DfsIterator<T> end_dfs_scan() const {
    return DfsIterator<T>(nullptr);

}


};


#endif
