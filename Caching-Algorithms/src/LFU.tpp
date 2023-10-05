#include "LFU.hpp"

template <typename T>
LFU<T>::LFU(std::size_t c) : cap{c} {}

template <typename T>
LFU<T>::~LFU() noexcept{}

template <typename T>
T LFU<T>::get(int key) {
    auto it = cach.find(key);
    if (it != cach.end()) {
        freqUpdate(key, it->second.second);
        return it->second.first;
    }
    return T{};
}

template <typename T>
void LFU<T>::put(int key, const T& val) {
    auto it = cach.find(key);
    if (it != cach.end()) {
        freqUpdate(key, it->second.second);
        cach[key] = {val, it->second.second};
    } else {
        if (cach.size() >= cap) {
            auto lastfreq = freq.begin()->first;
            cach.erase(freq[lastfreq].back());
            keys.erase(freq[lastfreq].back());
            freq[lastfreq].pop_back();
            if (freq[lastfreq].empty()) {
                freq.erase(lastfreq);
            }
        }
        cach[key] = {val, 1};
        freq[1].push_front(key);
        keys[key] = freq[1].begin();
    }
}

template <typename T>
void LFU<T>::freqUpdate(int key, std::size_t Freq) {
    freq[Freq].erase(keys[key]);
    if (freq[Freq].empty()) {
        freq.erase(Freq);
    }
    freq[Freq + 1].push_front(key);
    keys[key] = freq[Freq + 1].begin();
    cach[key].second = Freq + 1;
} 

