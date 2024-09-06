#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node{

private:
T value;
vector<Node<T>*> children;   // A vector who represent the children of the current Node


public:

//Constructor using initialization list
Node(const T& val): value(val){}  


//Destructor
~Node(){
    for(Node<T>* child : children){
        delete child;
    }
    children.clear();
}


const T& getValue(){
    return this->value;
}


void setValue(T val){
    this->value = val;
}


size_t numOfCh(){
    return children.size();
}


void addChild(Node<T>* newCh){
    children.push_back(newCh);        
}


vector<vector<T>*>& getChildren(){
    return children;
}

friend ostream& operator<<(ostream& stream, Node<T>* node){
    stream<< "Node value :" << node->value <<"\n";

    if(!node->children.empty()){
        for(Node<T>* child : node->children){
            stream<< child->value <<" ,";
        }
    }

    stream<<endl;
    return stream;
}



};

#endif
