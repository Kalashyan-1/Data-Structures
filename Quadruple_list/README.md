# Quadruple_list (Self-Organizing List)

Quadruple_list is a C++ class template that implements a self-organizing list (also known as a quadruple list). In this data structure, each node contains four pointers: one for the next node, one for the previous node, one for the node with an increasing order of values, and one for the node with a decreasing order of values.

## Table of Contents
- [Overview](#overview)
- [API](#api)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Overview

A self-organizing list is a data structure that reorganizes its elements based on their access frequency or other criteria to optimize certain operations. Quadruple_list extends the concept by maintaining both increasing and decreasing order pointers along with regular next and previous pointers.

### Features
- Supports insertion of elements while maintaining both increasing and decreasing order.
- Efficient element deletion by index.
- Provides three order options for element retrieval: Inserted, Increasing, and Decreasing.
- Automatically maintains order pointers for optimization.

## API

### Constructors

#### `Quadruple_list()`
Creates an empty quadruple list.

### Member Functions

#### `void insert(T val)`
Inserts a value into the quadruple list while maintaining order pointers.

#### `void erase(int index)`
Erases an element at the specified index.

#### `void print(Order order) const`
Prints the elements of the quadruple list in the specified order: Inserted, Increasing, or Decreasing.

## Complexity

- `insert(T val)`: O(N)
- `erase(int index)`: O(N)
- `print(Order order)`: O(N)

## Contributing

Contributions to the Quadruple_list class are welcome! If you have ideas for improvements, new features, or bug fixes, please open an issue or create a pull request. Make sure to follow C++ coding standards and include appropriate test cases.
