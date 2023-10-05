# Binary Search Tree (BST)

The Binary Search Tree (BST) class is a C++ implementation of a binary search tree data structure. A binary search tree is a hierarchical data structure that allows for efficient insertion, deletion, and searching of elements.

## Table of Contents

- [Usage](#usage)
- [API](#api)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Usage

To use the BST class in your C++ project, follow these steps:

1. Include the `bst.hpp` header file in your project.

```cpp
#include "bst.hpp"
```
2. Create an instance of the BST class with your desired data type, for example:
```cpp
BST<int> bst;
```

3. Use the provided methods to interact with the BST, such as insert, remove, find, and others.
```cpp
bst.insert(42);
bst.remove(15);
bool found = bst.find(42);
```
4. Don't forget to link your project with the appropriate source files.


## API

### `BST()`

- The default constructor creates an empty BST.

### `~BST()`

- The destructor cleans up the memory used by the BST.

### `void insert(T value)`

- Inserts a new element with value `value` into the BST.

### `void remove(T value)`

- Removes the element with value `value` from the BST.

### `bool find(T value)`

- Checks if the BST contains an element with the specified value and returns `true` if found, otherwise `false`.

### `int height()`

- Returns the height of the BST, which is the length of the longest path from the root to a leaf node.

### `void inorder()`

- Performs an in-order traversal of the BST, printing the elements in sorted order.

### `void postorder()`

- Performs a post-order traversal of the BST.

### `void preorder()`

- Performs a pre-order traversal of the BST.

### `void levelorder()`

- Performs a level-order traversal of the BST.

### `void printPredAndSucc(T value)`

- Prints the predecessor and successor of the element with the specified value.

## Complexity

- `insert(T value)`: Average-case time complexity is O(log n), worst-case time complexity is O(n) if the tree is unbalanced.
- `remove(T value)`: Average-case time complexity is O(log n), worst-case time complexity is O(n) if the tree is unbalanced.
- `find(T value)`: Average-case time complexity is O(log n), worst-case time complexity is O(n) if the tree is unbalanced.
- `height()`: O(n), where n is the number of nodes in the tree.
- `inorder()`, `postorder()`, `preorder()`: O(n).
- `levelorder()`: O(n).
- `printPredAndSucc(T value)`: O(log n) on average, O(n) in the worst case if the tree is unbalanced.



## Contributing

Contributions are welcome! If you'd like to improve this BST class implementation or have suggestions, feel free to open an issue or create a pull request.