// tsofiatouito2@gmail.com

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include "node.hpp"


template <typename T>
class Iterator{

    protected:
    Node<T>* curr;

    public:  
    Iterator(Node<T>* node_ptr = nullptr) : curr(node_ptr) {}

    virtual Node<T>* operator*() = 0;

    virtual Iterator& operator++() = 0;

    Node<T>* operator->() { return curr; }

    bool operator!=(const Iterator& other) const { return curr != other.curr; }

};




template <typename T>
class HeapOrderIterator {

    private:
        std::queue<Node<T>*> nodeQueue;

    public:
        // Constructor initializes the iterator with the root node
        HeapOrderIterator(Node<T>* root = nullptr) {
            if (root != nullptr){
                nodeQueue.push(root);
            }
    }

    // Advances the iterator to the next node in the heap order
    HeapOrderIterator& operator++() 
    {
        if (!nodeQueue.empty()) 
        {
            Node<T>* currentNode = nodeQueue.front();
            nodeQueue.pop();

            for (Node<T>* child : currentNode->getChildren()) 
            {
                if (child != nullptr) 
                {
                    nodeQueue.push(child);
                }
            }
        }

        return *this;
    }

    // Compares two iterators to check if they are not equal
    bool operator!=(const HeapOrderIterator& other) const 
    {
        // Iterators are not equal if one is not empty and the other is empty
        return !nodeQueue.empty() || !other.nodeQueue.empty();
    }

    // Dereference operator to get the current node
    Node<T>* operator*() const 
    {
        return nodeQueue.front();
    }

    // Arrow operator to access the members of the current node
    Node<T>* operator->() const 
    {
        return nodeQueue.front();
    }
};
//------------------------------------------------------------------------------------------


template <typename T>
class PreOrderIterator : public Iterator <T>{

    private:
    stack<Node<T>*> node_stack;


    public:
    PreOrderIterator(Node<T>* root){
        if(root != nullptr){
            node_stack.push(root);            //Insert the root into the stack
            this->curr = node_stack.top();
        }
        else{
            this->curr = nullptr;
        }
    }


    //advances the iterator to the next element and returns the updated iterator
    PreOrderIterator& operator++() override {
        if(!node_stack.empty()){
            this->curr = node_stack.top();   //The corrent Node point to the top of the stack
            node_stack.pop();

            //Iterate the children of the corrent Node and push them in reverse order into the stack
            const auto& children = this->curr->getChildren();
            for(auto it = children.rbegin() ; it != children.rend(); ++it){
                node_stack.push(*it);
            }
        }
        //Update the current Node
        this->curr = (!node_stack.empty()) ? node_stack.top() : nullptr ;

    return *this;
    }
    
    // Returns a reference to the current element the iterator points to
    Node<T>* operator*() override {
        return this->curr;
    }

};


//------------------------------------------------------------------------------------------
template <typename T>
class PostOrderIterator : public Iterator<T> {
private:
    stack<Node<T>*> node_stack;
    Node<T>* lastVisited = nullptr;

    // Helper function to advance the iterator
    void advance() {
        while (!node_stack.empty()) {
            Node<T>* topNode = node_stack.top();
            auto& children = topNode->getChildren();

            // Case 1: If the top node has children and we haven't visited any of them, push the children
            if (!children.empty() && 
                (lastVisited == nullptr || find(children.begin(), children.end(), lastVisited) == children.end())) {
                // Push the children in reverse order (right first, then left)
                for (auto it = children.rbegin(); it != children.rend(); ++it) {
                    node_stack.push(*it);
                }
            } 
            // Case 2: If all children have been visited, visit the node
            else {
                node_stack.pop();
                lastVisited = topNode;
                this->curr = topNode;
                return; // We have found the next node in post-order, so we can return
            }
        }

        // If the stack is empty, we're done with the traversal
        this->curr = nullptr;
    }

public:
    // Constructor: Initialize with the root node
    PostOrderIterator(Node<T>* root) {
        if (root) {
            node_stack.push(root); // Start by pushing the root node
            advance();             // Prepare the first element of the traversal
        } else {
            this->curr = nullptr;  // Handle case where the tree is empty
        }
    }

    // Advance to the next element in the post-order traversal
    PostOrderIterator& operator++() override {
        advance();
        return *this;
    }

    // Dereference to get the current node
    Node<T>* operator*() override {
        return this->curr;
    }
};



//------------------------------------------------------------------------------------------
template <typename T>
class InOrderIterator : public Iterator<T> {
private:
    stack<Node<T>*> node_stack;

    // Helper function to push all left descendants of the node
    void leftPush(Node<T>* node) {
        while (node) {
            node_stack.push(node);
            auto& children = node->getChildren();
            node = children.empty() ? nullptr : children[0];  // Push left child first
        }
    }

public:
    InOrderIterator(Node<T>* root) {
        if (root) {
            leftPush(root);  // Initialize with left-most path
            this->curr = !node_stack.empty() ? node_stack.top() : nullptr;
        } else {
            this->curr = nullptr;
        }
    }

    // Advances the iterator to the next element
    InOrderIterator& operator++() override {
        if (node_stack.empty()) {
            this->curr = nullptr;
            return *this;
        }

        Node<T>* node = node_stack.top();
        node_stack.pop();

        auto& children = node->getChildren();

        // If there is a right child, push all its left descendants
        if (children.size() > 1) {
            leftPush(children[1]);  // Right child at index 1
        }

        this->curr = !node_stack.empty() ? node_stack.top() : nullptr;
        return *this;
    }

    // Returns a reference to the current element the iterator points to
    Node<T>* operator*() override {
        return this->curr;
    }
};



//------------------------------------------------------------------------------------------
template <typename T>
class BfsIterator : public Iterator<T> {
private:
    queue<Node<T>*> node_queue;

public:
    BfsIterator(Node<T>* root) {
        if (root) {
            node_queue.push(root);
            this->curr = node_queue.front();
        } else {
            this->curr = nullptr;
        }
    }

    // Advances the iterator to the next element in the BFS traversal
    BfsIterator& operator++() override {
        if (node_queue.empty()) {
            this->curr = nullptr;
            return *this;
        }

        Node<T>* node = node_queue.front();
        node_queue.pop();

        auto& children = node->getChildren();
        for (auto child : children) {
            node_queue.push(child);
        }

        // Only update curr after popping the node
        this->curr = !node_queue.empty() ? node_queue.front() : nullptr;
        return *this;
    }

    // Returns a reference to the current element the iterator points to
    Node<T>* operator*() override {
        return this->curr;
    }
};



//------------------------------------------------------------------------------------------

template <typename T>
class DfsIterator : public PreOrderIterator<T> {
    
    public:
    DfsIterator(Node<T>* root) : PreOrderIterator<T>(root) {}

    Node<T>* operator*() override {
        return PreOrderIterator<T>::operator*();  //Call the base class's operator*
    }

    DfsIterator& operator++() override {
        PreOrderIterator<T>::operator++();        //Call the base class's operator++
        return *this;                             //Return the updated iterator
    }

};



