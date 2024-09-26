// tsofiatouito2@gmail.com

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "node.hpp"
#include "tree.hpp"
#include "Complex.hpp"

using namespace std;
using std::string;


//Demo file to demonstrate GUI printing by SFML
int main()
{


    /*Create a binary tree that contains doubles :

     *       root = 1.6
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.1
     *///-----------------------------------------

    Tree<double> tree;  
    Node<double> node1(1.6);       
    tree.add_root(&node1);
     
    Node<double> node2(1.2);
    Node<double> node3(1.3);
    Node<double> node4(1.4);
    Node<double> node5(1.5);
    Node<double> node6(1.1);

    // Add sub-nodes to the tree
    tree.add_sub_node(&node1, &node2);
    tree.add_sub_node(&node1, &node3);
    tree.add_sub_node(&node2, &node4);
    tree.add_sub_node(&node2, &node5);
    tree.add_sub_node(&node3, &node6);
    

    //print the tree to the screen using SFML
    cout << "Draw the binary tree using SFML :" << endl;
    // SFML setup
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Binary Tree Printing");
    
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

    // Clear the window
    window.clear(sf::Color::Magenta);

    // Draw the tree on the screen (passing font to avoid reloading)
    tree.drawTree(window);

    // Display the window content
    window.display();

}



    //Transform the binary tree into a minimum stack and traversal the result
    tree.toMinHeap();
   cout << "Transfer the tree to be a Min Heap." <<endl;
   cout << "Min Heap order :" <<endl;
   for (auto it = tree.min_heap_begin(); it != tree.min_heap_end(); ++it) 
   {
        cout << it->getValue() <<" " ;
    } 
    cout << "\n" << endl;  


    //print the tree to the screen using SFML
    cout << "Draw the transfer binary tree to min-heap using SFML :" << endl;
    
    sf::RenderWindow window2(sf::VideoMode(1000, 800), "Min-Heap tree Printing");
    
    while (window2.isOpen()) {
        sf::Event event;
        
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window2.close();
            }
        }

    // Clear the window
    window2.clear(sf::Color::Yellow);

    // Draw the tree on the screen (passing font to avoid reloading)
    tree.drawTree(window2);

    // Display the window content
    window2.display();

}



    /* Create a 3-ary tree that contains Complex :
    *
     *       root = 3 +5i
     *     /      |     \
     *   12 +6i   0    2 + 2i
     *   /        |
     * 1.5      1.6+ i
     */

    Tree<Complex, 3> three_ary_tree;
    
    Node<Complex> root(Complex(3, 5));
    Node<Complex> n1(Complex(12, 6));
    Node<Complex> n2(Complex(0, 0));
    Node<Complex> n3(Complex(2, 2));
    Node<Complex> n4(Complex(1.5, 0));
    Node<Complex> n5(Complex(1.6, 1));

    
    three_ary_tree.add_root(&root);
    three_ary_tree.add_sub_node(&root, &n1);
    three_ary_tree.add_sub_node(&root, &n2);
    three_ary_tree.add_sub_node(&root, &n3);
    three_ary_tree.add_sub_node(&n1, &n4);
    three_ary_tree.add_sub_node(&n2, &n5);




    //print the tree to the screen using SFML
    cout << "Draw the Complex 3-ary tree using SFML :" << endl;
    
    sf::RenderWindow window3(sf::VideoMode(1000, 800), "Complex 3-ary tree Printing");
    
    while (window3.isOpen()) {
        sf::Event event;
        
        while (window3.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window3.close();
            }
        }

    // Clear the window
    window3.clear(sf::Color::Blue);

    // Draw the tree on the screen (passing font to avoid reloading)
    three_ary_tree.drawTree(window3);

    // Display the window content
    window3.display();

}




}
