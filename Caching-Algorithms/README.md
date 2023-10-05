# Caching Algorithms

This directory contains three C++ implementations of caching algorithms: LFU (Least Frequently Used), LRU (Least Recently Used), and MRU (Most Recently Used). Caching algorithms are used to manage and optimize the use of limited memory or storage for frequently accessed data.

## Table of Contents

- [LFU (Least Frequently Used)](#lfu-least-frequently-used)
- [LRU (Least Recently Used)](#lru-least-recently-used)
- [MRU (Most Recently Used)](#mru-most-recently-used)
- [Usage](#usage)
- [Contributing](#contributing)

## LFU (Least Frequently Used)

The LFU algorithm keeps track of the usage frequency of each item in the cache and evicts the least frequently used items when the cache reaches its capacity.


## LRU (Least Recently Used)

The LRU algorithm keeps track of the access history of each item in the cache and evicts the least recently used items when the cache reaches its capacity.


## MRU (Most Recently Used)

The MRU algorithm keeps track of the access history of each item in the cache and evicts the most recently used items when the cache reaches its capacity.


## Usage

To use these caching algorithms in your C++ project, follow these steps for each algorithm:

1. Include the respective header file in your project, such as `LFU.hpp`, `LRU.hpp`, or `MRU.hpp`.

```cpp
#include "LFU.hpp" 
```
2. Create an instance of the respective caching algorithm class with your desired data type and capacity.

```cpp
LFU<int> lfuCache(100); 
```

3. Use the provided methods to interact with the BST, such as insert, remove, find, and others.
```cpp
lfuCache.put(1, 42); 
int value = lfuCache.get(1); 
```

4. Don't forget to link your project with the appropriate source files.



## Contributing
Contributions are welcome! If you'd like to improve these caching algorithm implementations or have suggestions, feel free to open an issue or create a pull request.