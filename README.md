tsofiatouito2@gmail.com
# K-ary Tree Container with Iterators

## Overview
This project implements a container for a k-ary tree, where each vertex can have at most `k` children. A special case is the binary tree (k=2). The tree is generic and can contain keys of any type, such as numbers, strings, or custom classes. The project includes a variety of iterators to traverse the tree in different ways, as well as functionality to transform a binary tree into a minimum heap.

## Files
- `node.hpp`: Defines the `Node` class, which represents a node in the tree. Each node contains a generic value and can accommodate children.
- `tree.hpp`: Defines the `Tree` class, which represents the k-ary tree and includes various methods for tree manipulation and traversal.
- `Complex.hpp`: Defines the `Complex` class, a custom class used to demonstrate the generic capabilities of the tree with complex numbers.
- `Complex.cpp`: Implements the methods of the `Complex` class.
- `makefile`: Contains build instructions for compiling the project, including rules for building the application and running tests.
- `doctest.h`: Header file for the Doctest framework, used for unit testing.
- `Test.cpp`: Contains unit tests for the tree and iterator classes, ensuring correctness and robustness.
- `TestCounter.cpp`: Additional tests to verify the functionality of counters and other features.
- `Demo.cpp`: Demonstrates the usage of the tree container and its iterators. Shows how to create a binary tree and a 3-ary tree, traverse them using various iterators, and print their contents.

## Features
- **Iterators:**
  - **Pre-Order Iterator:** Scans the tree in the order: current node -> left subtree -> right subtree. Works for binary trees; for general trees, it returns a DFS scan starting from the root.
  - **Post-Order Iterator:** Scans the tree in the order: left subtree -> right subtree -> current node. Works for binary trees; for general trees, it returns a DFS scan starting from the root.
  - **In-Order Iterator:** Scans the tree in the order: left subtree -> current node -> right subtree. Works for binary trees; for general trees, it returns a DFS scan starting from the root.
  - **BFS Iterator:** Scans the tree laterally (left to right). Works for general trees.
  - **DFS Iterator:** Scans the tree using the DFS algorithm. Works for general trees.
  - **Heap Iterator:** Transforms a binary tree into a minimum heap and provides an iterator to traverse the heap.

## Class Hierarchy
- **Node:** Contains a generic value and can have children.
- **Tree:** Consists of nodes and includes methods for manipulation and traversal.
- **Iterator Classes:** All iterators (except one) inherit from a generic iterator class. The iterators provide different ways to traverse the tree.

## Usage

1. To run the project:
   - Write the command in the terminal:
     ```bash
     make tree
     ```

2. Run the tree:
   ```bash
   ./tree
   ```

   
3. To Run the demonstrate GUI printing by SFML:
   - Write the command in the terminal:
   ```bash
   make gui_demo
   ```

5. Run the GUI :
   ```bash
   ./gui_demo
   ```
   This will display the tree using SFML. To continue with the program, close the SFML window after it appears.

## Testing
Unit tests are provided in `Test.cpp` and `TestCounter.cpp` using the Doctest framework. To run the tests:

1. Write the command in the terminal:
   ```bash
   make test
   ```

2. Run the test executable:
   ```bash
   ./Test
   ```
