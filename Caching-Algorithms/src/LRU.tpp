#include "LRU.hpp"

template <typename T>
LRU<T>::LRU(std::size_t capacity) : cap{capacity} {}

template <typename T>
LRU<T>::~LRU() noexcept {}

template <typename T>
T LRU<T>::get(int key) {
    auto it = cach.find(key);
    if (it == cach.end()) {
        return T{};
    }
    auto tmp = *it->second;
    val.erase(it->second);
    val.push_back(tmp);
    return it->second->second;
}

template <typename T>
void LRU<T>::put(int key, T value) {
    auto it = cach.find(key);
    
    if (it != cach.end()) {
        val.erase(it->second);
        val.push_back({key, value});
    } else {
        if (cach.size() >= cap) {
            cach.erase(val.front().first);
            val.pop_front();
        }
        val.push_back({key, value});
        cach[key] = std::prev(val.end());
    }
}

template <typename T>
void LRU<T>::print() {
    for (auto it = val.begin(); it != val.end(); ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;
}
