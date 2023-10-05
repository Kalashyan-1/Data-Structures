# AVL Tree

This is a C++ implementation of an AVL (Adelson-Velsky and Landis) tree, a self-balancing binary search tree. AVL trees ensure that the height difference between the left and right subtrees of any node (called the balance factor) is at most 1, which guarantees efficient operations for insertion, deletion, and retrieval.

## Table of Contents

- [Usage](#usage)
- [API](#api)
- [Contributing](#contributing)

## Usage

To use this AVL tree class in your C++ project, follow these steps:

1. Include the `avl.hpp` header file in your project.

```cpp
#include "avl.hpp"
```
2. Create an instance of the `AVL` class with your desired data type, for example:
```cpp
AVL<int> avlTree;
```

3. Use the provided methods to interact with the AVL tree, such as insert, remove, find, and others.
```cpp
avlTree.insert(42);
avlTree.remove(15);
bool found = avlTree.find(42);
```
4. Don't forget to link your project with the appropriate source files.



## API

### `AVL()`

- The default constructor creates an empty AVL tree.

### `~AVL() noexcept`

- The destructor cleans up the memory used by the AVL tree.

### `void insert(T val)`

- Inserts a new element with value `val` into the AVL tree while maintaining the balance property.

### `void remove(T val)`

- Removes the element with value `val` from the AVL tree while maintaining the balance property.

### `bool find(T value)`

- Checks if the AVL tree contains an element with the specified value and returns `true` if found, otherwise `false`.

### `int height()`

- Returns the height of the AVL tree, which is the length of the longest path from the root to a leaf node.

### `void inorder()`

- Performs an in-order traversal of the AVL tree, printing the elements in sorted order.

### `void postorder()`

- Performs a post-order traversal of the AVL tree.

### `void preorder()`

- Performs a pre-order traversal of the AVL tree.

### `void levelOrder()`

- Performs a level-order traversal of the AVL tree.


## Contributing

Contributions are welcome! If you'd like to improve this AVL tree implementation or have suggestions, feel free to open an issue or create a pull request.

