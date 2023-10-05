#include "blockArray.hpp"
#include <iostream>
int main() {
    BlockArray<int, 5> arr;
    arr.insert(6, 5);
    std::cout << arr[6];
    std::cout << ++arr[6];
    std::cout << arr.size();
}