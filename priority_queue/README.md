# Priority_queue

Priority_queue is a C++ class template that provides a priority queue data structure with customizable underlying containers and comparison functions.

## Table of Contents
- [Overview](#overview)
- [API](#api)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Overview

The Priority_queue class template is a flexible priority queue implementation that allows you to customize the underlying container type and the comparison function used to determine the priority of elements. It provides efficient operations for insertion, deletion, and retrieval of the highest-priority elements.

### Features
- Customizable underlying container (default is std::vector).
- Customizable comparison function (default is std::less).
- Supports common operations such as push, pop, and top.
- Provides options for custom allocators.

## API

### Constructors

#### `Priority_queue()`
Creates an empty priority queue.

#### `Priority_queue(const Compare& compare)`
Creates an empty priority queue with the specified comparison function.

#### `Priority_queue(const Compare& compare, const Container& cont)`
Creates a priority queue with the specified comparison function and initial container content.

### Member Functions

#### `const_reference top() const`
Returns a reference to the highest-priority element in the queue.

#### `bool empty() const`
Returns true if the priority queue is empty, otherwise false.

#### `size_type size() const`
Returns the number of elements in the priority queue.

#### `void push(const value_type& value)`
Inserts an element into the priority queue.

#### `void push(value_type&& value)`
Inserts an element into the priority queue by moving it.

#### `template <typename... Args> void emplace(Args&&... args)`
Constructs and inserts an element into the priority queue.

#### `void pop()`
Removes the highest-priority element from the priority queue.

#### `void swap(Priority_queue& other) noexcept`
Swaps the contents of two priority queues.

## Complexity

- `push(const value_type& value)`: O(log N)
- `push(value_type&& value)`: O(log N)
- `emplace(Args&&... args)`: O(log N)
- `pop()`: O(log N)
- `top()`: O(1)
- `empty()`: O(1)
- `size()`: O(1)

## Contributing

Contributions to the Priority_queue class are welcome! If you have ideas for improvements, new features, or bug fixes, please open an issue or create a pull request. Make sure to follow C++ coding standards and include appropriate test cases.
