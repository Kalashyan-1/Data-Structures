# Hashtable Class

The `Hashtable` class is a C++ implementation of a hash table data structure using separate chaining. A hash table is a data structure that stores key-value pairs and allows for efficient retrieval of values based on their keys.

## Table of Contents

- [OverView](#overview)
- [Usage](#usage)
- [API](#api)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Overview

The `Hashtable` class provides a hash table implementation that uses separate chaining to handle collisions. It allows you to store key-value pairs, retrieve values by their keys, and perform insertions and deletions efficiently. The class automatically resizes the underlying data structure when needed to maintain good performance.

## Usage

To use the `Hashtable` class in your C++ project, follow these steps:

1. Include the `Hashtable` header file in your source code:

   ```cpp
   #include "hashtable.hpp"
   ``` 

2. Create an instance of the Hashtable class:

    ```cpp
    Hashtable<KeyType, ValueType> hashtable;
    ```

3. Insert key-value pairs using the insert method:

    ```cpp
    hashtable.insert(std::make_pair(key, value));
    ```

4. Retrieve values by their keys using the operator[]:

    ```cpp
    ValueType retrievedValue = hashtable[key];
    ```
5. You can also check the current number of elements in the hash table using the size method:
    ```cpp
    std::size_t numElements = hashtable.size();
    ```


## API

### `void insert(const std::pair<T, U>& elem)`

Inserts a key-value pair into the hash table.

### `void erase(const std::pair<T, U> val)`

Removes a key-value pair from the hash table.

### `U& operator[](T key)`

Allows you to access the value associated with a key and modify it.

### `size_t size()`

Returns the number of elements currently stored in the hash table.



## Complexity

- `insert(const std::pair<T, U>& elem)`: Average-case time complexity is O(1), but it can increase if the load factor exceeds a threshold and the hash table needs to be resized.

- `erase(const std::pair<T, U> val)`: Average-case time complexity is O(1), but it can increase if the load factor exceeds a threshold and the hash table needs to be resized.

- `U& operator[](T key)`: Average-case time complexity is O(1), but it can increase if the load factor exceeds a threshold and the hash table needs to be resized.

- `size()`: O(1).



## Contributing

Contributions to the Hashtable class are welcome! If you have ideas for improvements or new features, feel free to open an issue or create a pull request.
