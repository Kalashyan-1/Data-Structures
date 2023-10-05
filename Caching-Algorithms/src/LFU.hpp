#ifndef LFU_HPP_
#define LFU_HPP_

#include <list>
#include <unordered_map>
#include <iostream>

template <typename T>
class LFU {
public:
    using listIter = typename std::list<T>::iterator;
    using freqList = typename std::list<int>;
    using keyVal = typename std::pair<T, std::size_t>;

    LFU(std::size_t);
    ~LFU() noexcept;
    T get(int key);
    void put(int key, const T& val);
    void print();
private:
    void freqUpdate(int, std::size_t);
private:
    std::size_t cap;
    std::unordered_map<int, keyVal> cach;
    std::unordered_map<std::size_t, freqList> freq;
    std::unordered_map<int, listIter> keys;
};

#include "LFU.tpp"

#endif  //LFU_HPP_
