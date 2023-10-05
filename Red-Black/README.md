# Red-Black Tree (RBTree)

RBTree is a C++ class template that implements a Red-Black Tree, a self-balancing binary search tree. Red-Black Trees provide efficient insertion, deletion, and searching operations while maintaining a balanced structure.

## Table of Contents
- [Overview](#overview)
- [API](#api)
- [Red-Black Tree Properties](#red-black-tree-properties)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Overview

A Red-Black Tree is a binary search tree with the following properties:
1. Each node is colored, either red or black.
2. The root is always black.
3. Every leaf ( NIL) is black.
4. Red nodes cannot have red children.
5. For each node, any simple path from this node to any of its descendant leaves has the same black depth (the number of black nodes).

These properties ensure that the tree remains approximately balanced, which guarantees that search, insert, and delete operations have O(log n) time complexity.

### Features
- Basic Red-Black Tree operations: insertion and deletion.
- Supports level order and in-order traversal.

## API

### Constructor

#### `RBTree()`
Creates an empty Red-Black Tree.

### Member Functions

#### `void insert(T val)`
Inserts an element with value `val` into the Red-Black Tree while maintaining the Red-Black Tree properties.

#### `void remove(T val)`
Removes an element with value `val` from the Red-Black Tree while maintaining the Red-Black Tree properties.

#### `void levelOrder()`
Performs a level-order traversal of the Red-Black Tree and prints the elements.

#### `void inorder()`
Performs an in-order traversal of the Red-Black Tree and prints the elements in sorted order.



## Complexity

- Insertion: O(log n)
- Deletion: O(log n)
- Search: O(log n)
- Level-Order Traversal: O(n)
- In-Order Traversal: O(n)

## Contributing

Contributions to the RBTree class are welcome! If you have ideas for improvements, new features, or bug fixes, please open an issue or create a pull request. Make sure to follow C++ coding standards and include appropriate test cases.
