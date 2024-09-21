//tsofiatouito2@gmail.com

#include "doctest.h"
#include "tree.hpp"
#include "node.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;
using std::string;
using std::cout;
using std::endl;

//node test
TEST_CASE("Node operations") 
{
    Node<double> node(3.14);

    // Test Node creation and value access
    CHECK(node.getValue() == 3.14);

    node.setValue(2.718);
     CHECK(node.getValue() == 2.718);

    // Test Children operations
    Node<int> parent(10);
    Node<int> child1(20);
    Node<int> child2(30);

    parent.addChild(&child1);
    parent.addChild(&child2);

     CHECK(parent.getChildren().size() == 2);
     

    // Test Clear children
    Node<char> parentChar('A');
    Node<char> childChar1('B');
    Node<char> childChar2('C');

    parentChar.addChild(&childChar1);
    parentChar.addChild(&childChar2);

    CHECK(parentChar.getChildren().size() == 2);

}



//tree test
TEST_CASE("Add root and add sub-nodes") 
{
    
    Tree<int> tree;
    Node<int> root (1);
    Node<int> child1 (2);
    Node<int> child2 (3);

    CHECK_NOTHROW(tree.add_root(&root));
    CHECK_THROWS(tree.add_root(&root));        // Adding root again should throw an exception

    CHECK_NOTHROW(tree.add_sub_node(&root, &child1));

    CHECK_NOTHROW(tree.add_sub_node(&root, &child2));

   
}



TEST_CASE("Traversal operations") 
{
    
    Node<int>root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    
    Tree<int> tree;
    tree.add_root(&root);
    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);
    

    //"Pre-order traversal"
        std::vector<int> expected1 = {1, 2, 3};
        std::vector<int> result1;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) 
        {
            result1.push_back(it->getValue());
        }
        CHECK(result1 == expected1);
    

    //"Post-order traversal"
        vector<int> expected2 = {2, 3, 1};
        vector<int> result2;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            result2.push_back(it->getValue());
        }
        CHECK(result2 == expected2);
    

   //"In-order traversal"
        vector<int> expected3 = {2, 1, 3};
        vector<int> result3;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            result3.push_back(it->getValue());
        }
        CHECK(result3 == expected3);
    

    //"BFS scan"
        vector<int> expected4 = {1, 2, 3};
        vector<int> result4;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result4.push_back((*it)->getValue());
        }
        CHECK(result4 == expected4);
    

    //"DFS scan"
        vector<int> expected5 = {1, 2, 3};
        vector<int> result5;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result5.push_back(it->getValue());
        }
        CHECK(result5 == expected5);
    

    
}

TEST_CASE("Heapify and min-heap order") {
    
    Node<int>root(3);
    Node<int> child1(2);
    Node<int> child2(4);
    Tree<int> tree;
    tree.add_root(&root);
    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);

    //"Heapify the tree") 
        tree.toMinHeap();
        // After heapify, the tree should be rearranged into a min-heap structure
        std::vector<int> expected6 = {2, 3, 4};
        std::vector<int> result6;
        for (auto it = tree.min_heap_begin(); it != tree.min_heap_end(); ++it) 
        {
            result6.push_back(it->getValue());
        }

        CHECK(result6 == expected6);
    

  
  
}

TEST_CASE("Binary Tree of Doubles") {
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    Tree<double, 2> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    // Validate pre-order traversal
    std::vector<double> expected_preorder = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
    std::vector<double> result_preorder;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result_preorder.push_back(node->getValue());
    }
    CHECK(result_preorder == expected_preorder);

    // Validate post-order traversal
    std::vector<double> expected_postorder = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
    std::vector<double> result_postorder;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        result_postorder.push_back(node->getValue());
    }
    CHECK(result_postorder == expected_postorder);

    // Validate in-order traversal
    std::vector<double> expected_inorder = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
    std::vector<double> result_inorder;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        result_inorder.push_back(node->getValue());
    }
    CHECK(result_inorder == expected_inorder);

    // Validate BFS scan
    std::vector<double> expected_bfs = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
    std::vector<double> result_bfs;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result_bfs.push_back((*node)->getValue());
    }
    CHECK(result_bfs == expected_bfs);
}

TEST_CASE("3-ary Tree of Doubles") 
{
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    Tree<double, 3> tree; // 3-ary tree that contains doubles.
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&root_node, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    // Validate BFS scan
    std::vector<double> expected_bfs = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
    std::vector<double> result_bfs;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result_bfs.push_back((*node)->getValue());
    }
    CHECK(result_bfs == expected_bfs);
}


TEST_CASE("3-ary Tree of Strings") 
{
    Node<string> root_node("Hi");
    Node<string> ns1("My");
    Node<string> ns2("name");
    Node<string> ns3("is");
    Node<string> ns4("Tsofia");
    Node<string> ns5("Touito");
    Node<string> ns6("<3");
    
    // 3-ary tree that contains strings.
    Tree<string, 3> tree;
     
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &ns1);
    tree.add_sub_node(&root_node, &ns2);
    tree.add_sub_node(&root_node, &ns3);
    tree.add_sub_node(&ns1, &ns4);
    tree.add_sub_node(&ns2, &ns5);
    tree.add_sub_node(&ns3, &ns6);

    //  DFS scan checking
    vector<string> expected_dfs = {"Hi", "my", "name", "is", "Tsofia", "Touito", "<3"};
    vector<string> result_dfs;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) 
    {
        result_dfs.push_back(node->getValue());
    }
    CHECK(result_dfs == expected_dfs);

    // check if in oeder scan do dfs becuse tree have 3 child
    vector<string> result_inorder;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) 
    {
        result_inorder.push_back(node->getValue());
    }
    CHECK(expected_dfs == result_inorder);
}

TEST_CASE("Try addaing more child then K")
{  
    Node<int>root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(4);
     //trying to add 4 chils to 3-tree
    Tree<int,3> tree;
    tree.add_root(&root);
    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);
    tree.add_sub_node(&root, &child3);
    CHECK_THROWS(tree.add_sub_node(&root, &child4));
    
    
    
    Node<int>root1(1);
    Node<int> child11(2);
    Node<int> child21(3);
    Node<int> child31(4);
 
    //trying to add 3 chils to 3-tree
    Tree<int> tree1;
    tree1.add_root(&root1);
    tree1.add_sub_node(&root1, &child11);
    CHECK_NOTHROW(tree1.add_sub_node(&root1, &child21));
    
    CHECK_THROWS(tree.add_sub_node(&root, &child31));
}
