/**
 * Demo app for Ex4
 */#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "Complex.hpp"

using namespace std;
using std::string;

int main()
{
    Node<double> node1(1.1);
    Tree<double> tree;         // Binary tree that contains doubles
    tree.add_root(&node1);
    
    cout << &node1;  
    Node<double> node2(1.2);
    Node<double> node3(1.3);
    Node<double> node4(1.4);
    Node<double> node5(1.5);
    Node<double> node6(1.6);

    cout << &node1;

    // Add sub-nodes to the tree
    tree.add_sub_node(&node1, &node2);
    tree.add_sub_node(&node1, &node3);
    tree.add_sub_node(&node2, &node4);
    tree.add_sub_node(&node2, &node5);
    tree.add_sub_node(&node3, &node6);
    
    cout << &node1;
    cout << &node2;
    cout << &node3;

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    // Try to add a child for a parent with a maximum amount of children
    try {
        tree.add_sub_node(&node1, &node6);
    }
    catch(const out_of_range &e) {
        cout << e.what() << endl; // Should print: "The parent Node already has the maximum number of children."
    }

    // Try to add sub-node for a tree without a root
    Tree<double> tree1;
    try {
        tree1.add_sub_node(&node1, &node6);
    }
    catch(const logic_error &e) {
        cout << e.what() << endl; // Should print: "There is no root for the tree."
    }

    Tree<string> strTree;

    Node<string> nodeS1("root");
    strTree.add_root(&nodeS1);

    Node<string>* nodeS2 = new Node<string>("new root");  // Allocate memory
    try {
        strTree.add_root(nodeS2);  // Try to add another root
    }
    catch(const logic_error &e) {
        cout << e.what() << endl; // Should print: "The tree already has a root."
    }

    // Pre-order traversal
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        cout << it->getValue() << " " << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    // Post-order traversal
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        cout << it->getValue() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    // In-order traversal
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        cout << it->getValue() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    // Breadth-first search traversal
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        cout << it->getValue() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // Try to create a 3-ary tree
    Tree<double, 3> three_ary_tree;  // 3-ary tree.
    three_ary_tree.add_root(&node1);
    three_ary_tree.add_sub_node(&node1, &node2);
    three_ary_tree.add_sub_node(&node1, &node3);
    three_ary_tree.add_sub_node(&node1, &node4);
    three_ary_tree.add_sub_node(&node2, &node5);
    three_ary_tree.add_sub_node(&node3, &node6);

    // The tree should look like:
    /*
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    delete nodeS2;  // Don't forget to free the dynamically allocated memory
}
