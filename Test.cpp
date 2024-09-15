// tsofiatouito2@gmail.com

#include "doctest.h"
#include "tree.hpp"
#include "node.hpp"
#include "Complex.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <vector>
#include <string>

// Node class for the tests
class TestNode : public Node<int> {
public:
    TestNode(int value) : Node<int>(value) {}
    TestNode(int value, std::vector<Node<int>*> children) : Node<int>(value, children) {}
};

// Tree class test
TEST_CASE("Tree operations") 
{
    Tree<int, 2> tree; // Binary tree

    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);

    // Test adding root
    CHECK_NOTHROW(tree.add_root(&root));
    CHECK_THROWS(tree.add_root(&root)); // Should throw exception if root already exists

    // Test adding sub-nodes
    CHECK_NOTHROW(tree.add_sub_node(&root, &child1));
    CHECK_NOTHROW(tree.add_sub_node(&root, &child2));
    CHECK_THROWS(tree.add_sub_node(&root, &child3)); // Should throw exception, only 2 children allowed

    // Test getting root
    CHECK(tree.get_root() == &root);

    // Test drawing tree (requires valid SFML setup)
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");
    CHECK_NOTHROW(tree.drawTree(window));

    // Test min-heap transformation
    root.setValue(5);
    child1.setValue(3);
    child2.setValue(4);
    CHECK_NOTHROW(tree.toMinHeap());

    // Validate min-heap order
    CHECK(root.getValue() == 3);
    CHECK(child1.getValue() == 4);
    CHECK(child2.getValue() == 5);

    // Test iterators
    std::vector<int> expectedPreOrder = {3, 4, 5};
    std::vector<int> resultPreOrder;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) 
    {
        resultPreOrder.push_back(it->getValue());
    }
    CHECK(resultPreOrder == expectedPreOrder);

    // Validate post-order traversal
    std::vector<int> expectedPostOrder = {4, 5, 3};
    std::vector<int> resultPostOrder;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) 
    {
        resultPostOrder.push_back(it->getValue());
    }
    CHECK(resultPostOrder == expectedPostOrder);

    // Validate in-order traversal (Binary tree)
    std::vector<int> expectedInOrder = {4, 3, 5};
    std::vector<int> resultInOrder;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) 
    {
        resultInOrder.push_back(it->getValue());
    }
    CHECK(resultInOrder == expectedInOrder);

    // Validate BFS scan
    std::vector<int> expectedBFS = {3, 4, 5};
    std::vector<int> resultBFS;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) 
    {
        resultBFS.push_back(it->getValue());
    }
    CHECK(resultBFS == expectedBFS);

    // Validate DFS scan
    std::vector<int> expectedDFS = {3, 4, 5};
    std::vector<int> resultDFS;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) 
    {
        resultDFS.push_back(it->getValue());
    }
    CHECK(resultDFS == expectedDFS);
}

TEST_CASE("Tree operations with non-binary tree") 
{
    Tree<int, 3> tree; // Ternary tree

    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);

    CHECK_NOTHROW(tree.add_root(&root));
    CHECK_NOTHROW(tree.add_sub_node(&root, &child1));
    CHECK_NOTHROW(tree.add_sub_node(&root, &child2));
    CHECK_NOTHROW(tree.add_sub_node(&root, &child3));
    CHECK_THROWS(tree.add_sub_node(&root, &child4)); // Should throw exception, only 3 children allowed

    // Test iterators for non-binary tree
    std::vector<int> expectedPreOrder = {1, 2, 3, 4};
    std::vector<int> resultPreOrder;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) 
    {
        resultPreOrder.push_back(it->getValue());
    }
    CHECK(resultPreOrder == expectedPreOrder);

    // Validate post-order traversal for non-binary tree
    std::vector<int> expectedPostOrder = {2, 3, 4, 1};
    std::vector<int> resultPostOrder;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) 
    {
        resultPostOrder.push_back(it->getValue());
    }
    CHECK(resultPostOrder == expectedPostOrder);

    // Validate in-order traversal for non-binary tree
    std::vector<int> expectedInOrder = {2, 1, 3, 4};
    std::vector<int> resultInOrder;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) 
    {
        resultInOrder.push_back(it->getValue());
    }
    CHECK(resultInOrder == expectedInOrder);

    // Validate BFS scan for non-binary tree
    std::vector<int> expectedBFS = {1, 2, 3, 4};
    std::vector<int> resultBFS;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) 
    {
        resultBFS.push_back(it->getValue());
    }
    CHECK(resultBFS == expectedBFS);

    // Validate DFS scan for non-binary tree
    std::vector<int> expectedDFS = {1, 2, 3, 4};
    std::vector<int> resultDFS;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) 
    {
        resultDFS.push_back(it->getValue());
    }
    CHECK(resultDFS == expectedDFS);
}
