# Queue (FIFO - First-In-First-Out)

Queue is a C++ class template that implements a basic queue data structure following the FIFO (First-In-First-Out) principle. It allows you to efficiently manage a collection of elements with operations such as enqueueing, dequeueing, and checking the front and back elements.

## Table of Contents
- [Overview](#overview)
- [API](#api)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Overview

A queue is a linear data structure that follows the FIFO order. Elements are added to the back of the queue and removed from the front. Queue provides a simple and efficient way to manage elements in the order they were added, making it useful for a wide range of applications.

### Features
- Basic queue operations: enqueue, dequeue, front, back, empty, and size.
- Supports both L-value and R-value insertion.
- Allows emplacement of elements using variadic templates.

## API

### Constructors

#### `Queue()`
Creates an empty queue.

### Copy and Move Constructors

#### `Queue(const Queue&)`
Creates a new queue by copying the elements of an existing queue.

#### `Queue(Queue&&)`
Creates a new queue by moving the elements of an existing queue.

### Copy and Move Assignment Operators

#### `Queue& operator=(const Queue&)`
Assigns the elements of an existing queue to this queue by copying.

#### `Queue& operator=(Queue&&)`
Assigns the elements of an existing queue to this queue by moving.

### Member Functions

#### `const T& front()`
Returns a constant reference to the front element of the queue.

#### `const T& back()`
Returns a constant reference to the back element of the queue.

#### `bool empty() const`
Checks if the queue is empty.

#### `std::size_t size() const`
Returns the number of elements in the queue.

#### `void push(const T& value)`
Enqueues an element at the back of the queue.

#### `void push(T&& value)`
Enqueues an element at the back of the queue using move semantics.

#### `template<typename... Args> void emplace(Args&&... args)`
Enqueues an element at the back of the queue by constructing it in-place using variadic templates.

#### `void pop()`
Dequeues (removes) the front element of the queue.

#### `void swap(Queue& other) noexcept`
Swaps the contents of two queues efficiently.

## Complexity

- `front()`: O(1)
- `back()`: O(1)
- `empty()`: O(1)
- `size()`: O(1)
- `push(const T& value)`: O(1)
- `push(T&& value)`: O(1)
- `emplace(Args&&... args)`: O(1)
- `pop()`: O(1)
- `swap(Queue& other)`: O(1)

## Contributing

Contributions to the Queue class are welcome! If you have ideas for improvements, new features, or bug fixes, please open an issue or create a pull request. Make sure to follow C++ coding standards and include appropriate test cases.
