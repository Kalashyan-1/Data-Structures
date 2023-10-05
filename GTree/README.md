# GTree Class

The `GTree` class is a C++ implementation of a General Tree data structure. A General Tree is a hierarchical data structure that consists of nodes where each node can have an arbitrary number of child nodes.

## Table of Contents

- [Overview](#overview)
- [API](#api)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Overview

The `GTree` class allows you to create and manipulate a General Tree with nodes that contain lambda functions. Each node in the tree stores a lambda function that takes an integer as input and returns an integer. This design allows you to perform custom operations on the data stored in the tree.

## API

### `void insert(std::function<int(int)> val, int level, int pos)`

Inserts a new node with the specified lambda function `val` at a given `level` and `pos` within the tree. The `level` indicates the depth of the tree, and the `pos` indicates the position of the node at that level.

### `int exec(int num)`

Executes the lambda functions stored in the tree with the input `num` and returns the result. The lambda functions are executed in a breadth-first manner.

### `int height()`

Returns the height of the tree, which is the length of the longest path from the root to a leaf node.



## Complexity

- `insert(std::function<int(int)> val, int level, int pos)`: Average-case time complexity is O(level + pos), where `level` is the depth of the tree and `pos` is the position of the node at that level.

- `exec(int num)`: Time complexity is O(N), where N is the number of nodes in the tree.

- `height()`: Time complexity is O(N), where N is the number of nodes in the tree.


## Contributing

Contributions to the `GTree` class are welcome! If you have ideas for improvements or new features, feel free to open an issue or create a pull request.
