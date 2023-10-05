#include "MRU.hpp"

template <typename T>
MRU<T>::MRU(std::size_t capacity) : cap{capacity} {}

template <typename T>
MRU<T>::~MRU() noexcept {}

template <typename T>
T MRU<T>::get(int key) {
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
void MRU<T>::put(int key, T value) {
    auto it = cach.find(key);
    
    if (it != cach.end()) {
        val.erase(it->second);
        val.push_back({key, value});
    } else {
        if (cach.size() >= cap) {
            cach.erase(val.back().first);
            val.pop_back();
        }
        val.push_back({key, value});
        cach[key] = std::prev(val.end());
    }
}

template <typename T>
void MRU<T>::print() {
    for (auto it = val.begin(); it != val.end(); ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;
}
