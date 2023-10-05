#ifndef MRU_
#define MRU_

#include <iostream>
#include <list>
#include <unordered_map>

template <typename T>
class MRU {
public:
    using listIter = typename std::list<std::pair<int, T>>::iterator;

    MRU(std::size_t capacity);
    ~MRU() noexcept;

    T get(int key);
    void put(int key, T val);
    void print();

private:
    std::size_t cap;
    std::list<std::pair<int, T>> val;
    std::unordered_map<int, listIter> cach;
};

#include "MRU.tpp"

#endif  //MRU_