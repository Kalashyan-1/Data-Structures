# BlockArray

The BlockArray class is a C++ implementation of a dynamic array that efficiently manages memory by using blocks of fixed size. This class provides a flexible and memory-efficient alternative to traditional dynamic arrays and allows you to store and manipulate a collection of elements.

## Table of Contents

- [Usage](#usage)
- [API](#api)
- [Contributing](#contributing)

## Usage

To use the BlockArray class in your C++ project, follow these steps:

1. Include the `blockarray.hpp` header file in your project.

```cpp
#include "blockarray.hpp"
```
2. Create an instance of the BlockArray class with your desired element type, for example:

```cpp
BlockArray<int> myArray;
```

3. Use the provided methods to add, access, and remove elements from the array.
```cpp
myArray.pushBack(42);       
int value = myArray[0];     
myArray.popBack();         
```

4. You can also query the size and capacity of the array using size() and capacity() methods.
```cpp
std::size_t arraySize = myArray.size();
std::size_t arrayCapacity = myArray.capacity();
```

5. Don't forget to link your project with the appropriate source files.



## API

### `BlockArray()`

- The default constructor creates an empty BlockArray.

### `~BlockArray()`

- The destructor cleans up the memory used by the BlockArray.

### `void pushBack(const T& value)`

- Adds an element with the specified value to the end of the BlockArray.

### `void popBack()`

- Removes the last element from the BlockArray.

### `T& operator[](std::size_t index)`

- Returns a reference to the element at the specified index.

### `const T& operator[](std::size_t index) const`

- Returns a constant reference to the element at the specified index.

### `std::size_t size() const`

- Returns the number of elements currently stored in the BlockArray.

### `std::size_t capacity() const`

- Returns the current capacity of the BlockArray.




## Contributing

Contributions are welcome! If you'd like to improve this BlockArray class implementation or have suggestions, feel free to open an issue or create a pull request.