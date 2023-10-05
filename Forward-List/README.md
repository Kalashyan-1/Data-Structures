# Forward-List

The Forward-List class is a C++ implementation of a singly-linked list, often referred to as a forward list. It provides efficient memory usage and basic operations for managing a collection of elements.

## Table of Contents

- [Usage](#usage)
- [API](#api)
- [Complexity](#complexity)
- [Contributing](#contributing)

## Usage

To use the Forward-List class in your C++ project, follow these steps:

1. Include the `forward_list.hpp` header file in your project.

```cpp
#include "forward_list.hpp"
```

2. Create an instance of the FList class with your desired data type, for example:
```cpp
FList<int> myList;
```

3. Use the provided methods to interact with the forward list, such as insert, erase, push_front, pop_front, and print.
```cpp
myList.push_front(42);        
myList.insert(10, 2);        
myList.erase(1);              
myList.pop_front();          
myList.print();              
```
4. Don't forget to link your project with the appropriate source files.



## API

### `FList()`

- The default constructor creates an empty forward list.

### `~FList()`

- The destructor cleans up the memory used by the forward list.

### `void insert(T n, std::size_t index)`

- Inserts an element with value `n` at the specified index in the forward list.

### `void erase(int n)`

- Removes the element at the specified index in the forward list.

### `void push_front(T&)`

- Adds an element with the specified value to the front of the forward list.

### `void push_front(T&&)`

- Adds an element with the specified value (rvalue) to the front of the forward list.

### `void pop_front()`

- Removes the first element from the forward list.

### `void print()`

- Prints the elements in the forward list.



## Complexity

- `FList()`: O(1)
- `~FList()`: O(n), where n is the number of elements in the list.
- `void insert(T n, std::size_t index)`: O(n) in the worst case, where n is the index.
- `void erase(int n)`: O(n) in the worst case, where n is the index.
- `void push_front(T&)`: O(1)
- `void push_front(T&&)`: O(1)
- `void pop_front()`: O(1)
- `void print()`: O(n), where n is the number of elements in the list.


## Contributing
Contributions are welcome! If you'd like to improve this Forward-List class implementation or have suggestions, feel free to open an issue or create a pull request.