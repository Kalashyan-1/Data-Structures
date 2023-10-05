#ifndef LRM_
#define LRM_

#include <iostream>
#include <list>
#include <unordered_map>

template <typename T>
class LRU {
public:

    using listIter = typename std::list<std::pair<int, T>>::iterator;

    LRU(std::size_t capacity);
    ~LRU() noexcept;

    T get(int key);
    void put(int key, T val);
    void print();

private:
    std::size_t cap;
    std::list<std::pair<int, T>> val;
    std::unordered_map<int, listIter> cach;
};

#include "LRU.tpp"

#endif  //endif

