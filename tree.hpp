// tsofiatouito2@gmail.com

#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
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
  ~Tree() { delete root; } 


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

//------------------------------------------------------------------------------------------
//Draw the tree using SFML

void drawTree(sf::RenderWindow& window) {
    if (!this->root) {
        cout << "The tree has no root." << endl;
        return;
    }

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        cout << "Failed to load font!" << endl;
        return;
    }

    float offsetX = 600.f;  // Horizontal space between children nodes
    float offsetY = 150.f;  // Vertical space between levels

    drawNode(window, root, 400.f, 50.f, offsetX, offsetY, font);  // Pass root, not &root
}



void drawNode(sf::RenderWindow& window, Node<T>* node, float x, float y, float offsetX, float offsetY, sf::Font& font) {
    if (!node) {
        return;
    }

    // Draw the shape of Node
    sf::CircleShape circle(30.f);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(3.f);
    circle.setPosition(x - circle.getRadius(), y - circle.getRadius()); // Center the circle
    window.draw(circle);  // Draw in window

    // Draw the value of the node into the shape
    sf::Text value(node->getStrVal(), font);
    value.setCharacterSize(12);
    value.setFillColor(sf::Color::Black);
    value.setPosition(x - value.getLocalBounds().width / 2.f, y - value.getLocalBounds().height / 2.f); 
    window.draw(value);

    // Draw the children of the current node
    auto& children = node->getChildren();
    if (!children.empty()) {
        float childOffsetX = offsetX / (children.size() + 1);   // Calculate the intervals between the children 

        for (size_t i = 0; i < children.size(); i++) {  // Change int to size_t
            if (children[i]) {
                float child_x = x - offsetX /2 + (i + 1) * childOffsetX;  // Update the child's position
                float child_y = y + offsetY;  // Correct vertical position

                // Draw line from parent to child
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, y)),
                    sf::Vertex(sf::Vector2f(child_x, child_y))
                };
                window.draw(line, 2, sf::Lines);

                // Recursively draw children
                drawNode(window, children[i], child_x, child_y, offsetX / 2.f, offsetY, font);
            }
        }
    }
}



void toMinHeap(){

    if(K!=2){
        throw logic_error("The tree isn't a binary tree .");
    }

    if(!root){
        throw logic_error("There is no root for the tree.");
    }

    myHeap(this->root);   //A binary tree that has a root
}





void myHeap(Node<T>* node) {
    if (!node) {
        return;
    }

    // A binary tree has only 2 children, handle cases where children might be nullptr
    Node<T>* leftChild = node->getChildren().size() > 0 ? node->getChildren()[0] : nullptr;
    Node<T>* rightChild = node->getChildren().size() > 1 ? node->getChildren()[1] : nullptr;

    // Recursive call for the left sub-tree and the right sub-tree
    myHeap(leftChild);
    myHeap(rightChild);

    // Find the smallest value
    Node<T>* smallest = node;

    if (leftChild && leftChild->getValue() < smallest->getValue()) {
        smallest = leftChild;
    }
    if (rightChild && rightChild->getValue() < smallest->getValue()) {
        smallest = rightChild;
    }

    // Check if the parent is larger than its smallest child
    if (smallest != node) {
        T temp = node->getValue();
        node->setValue(smallest->getValue());
        smallest->setValue(temp);
        myHeap(smallest);
    }
}




////Iterators Begin&End function
//---------------------------------------------------------------------------------------------------------------


// Transform the tree into a min-heap and return an iterator to the beginning
HeapOrderIterator<T> min_heap_begin() const{
    return HeapOrderIterator<T>(root);   // Return iterator starting from root
}

// Return an iterator marking the end 
HeapOrderIterator<T> min_heap_end() const{

    if constexpr(K != 2) {  //For a general tree (Not a binery treee) print an error
        throw invalid_argument("The tree isn't a binary tree .");
    }
        
    else{
        return HeapOrderIterator<T>(nullptr); 
    }
}




//---------------------------------------------------------------------------------------------------------------


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


//-----------------------------------------------------------------------------------------------


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


//---------------------------------------------------------------------------------------------


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
//-----------------------------------------------------------------------------


BfsIterator<T> begin_bfs_scan() const {
    return BfsIterator<T>(root);
}

BfsIterator<T> end_bfs_scan() const {
    return BfsIterator<T>(nullptr);

}


//-----------------------------------------------------------------------------


DfsIterator<T> begin_dfs_scan() const {
    return DfsIterator<T>(root);
}

DfsIterator<T> end_dfs_scan() const {
    return DfsIterator<T>(nullptr);

}


};


#endif
