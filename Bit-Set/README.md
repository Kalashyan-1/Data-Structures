# Bitset

The Bitset class is a C++ implementation of a fixed-size bitset that provides efficient storage and manipulation of individual bits. This class is particularly useful when you need to manage a set of binary flags or perform bit-level operations on a collection of bits.

## Table of Contents

- [Usage](#usage)
- [API](#api)
- [Contributing](#contributing)

## Usage

To use the Bitset class in your C++ project, follow these steps:

1. Include the `bitset.hpp` header file in your project.

```cpp
#include "bitset.hpp"
```

2. Create an instance of the Bitset class with your desired bitset size, for example:

```cpp
Bitset<8> myBitset;
```

3. Use the provided methods to manipulate and query the bitset, such as set, reset, all, any, and others.
```cpp
myBitset.set(3);     
myBitset.reset(1);   
bool isSet = myBitset[2];  
```
4. You can also use the << operator to print the bitset.
```cpp
std::cout << myBitset << std::endl;  
```
5. Don't forget to link your project with the appropriate source files.




## API

### `Bitset()`

- The default constructor creates an empty bitset with all bits initialized to 0.

### `~Bitset()`

- The destructor cleans up the memory used by the bitset.

### `Bitset& set()`

- Sets all bits in the bitset to 1.

### `Bitset& set(std::size_t pos)`

- Sets the bit at the specified position `pos` to 1.

### `Bitset& reset()`

- Resets all bits in the bitset to 0.

### `Bitset& reset(std::size_t pos)`

- Resets the bit at the specified position `pos` to 0.

### `bool all()`

- Returns `true` if all bits in the bitset are set (1), otherwise returns `false`.

### `bool any()`

- Returns `true` if any bit in the bitset is set (1), otherwise returns `false`.

### `bool none()`

- Returns `true` if none of the bits in the bitset are set (all are 0), otherwise returns `false`.

### `bool operator[](std::size_t pos)`

- Returns the value of the bit at the specified position `pos`.

### `friend std::ostream& operator<<(std::ostream& stream, const Bitset<T>& bitset)`

- Overloaded `<<` operator to print the bitset to the output stream.




## Contributing

Contributions are welcome! If you'd like to improve this Bitset class implementation or have suggestions, feel free to open an issue or create a pull request.