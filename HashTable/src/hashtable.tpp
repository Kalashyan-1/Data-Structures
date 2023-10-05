#include "hashtable.hpp"

template <typename T, typename U>
int Hashtable<T, U>::hash(T val) {
    char* ch = (char*)(&val);
    std::string tmp(ch);
    int res = 5678;
    for (int i = 0; i < tmp.size(); ++i) {
        res = (((res << 5) + res) + static_cast<unsigned char>(tmp[i])) % table.capacity();
    }
    return res;
}

template <typename T, typename U>
U& Hashtable<T, U>::operator[](T key) {
    int index = hash(key);
     for (auto& keyValue : table[index]) {
        if (keyValue.first == key) {
            return keyValue.second;
        }
    }
    table[index].push_back(std::make_pair(key, U()));
    ++elemCount;
    if (static_cast<double>(elemCount) / table.size() >= Threshold)
        resize(nextPrime());

    return table[index].back().second;
}


template <typename T, typename U>
void Hashtable<T, U>::insert(const std::pair<T, U>& elem) {
    double LF = static_cast<double>(elemCount) / table.capacity();
    if (LF >= Threshold) {
        resize(nextPrime());
    }
    table[hash(elem.first)].push_back(elem);
    ++elemCount;
}

template <typename T, typename U>
void Hashtable<T, U>::resize(std::size_t newSize) {
    std::vector<std::list<std::pair<T, U>>> newTable(newSize);
    for (const auto& lists : table) {
        for (const auto& val : lists) {
            int index = hash(val.first);
            newTable[index].push_back(val);
        }
    }
    table = std::move(newTable);
}


template <typename T, typename U>
void Hashtable<T, U>::erase(const std::pair<T, U> val) {
    int index = hash(val.first);
    auto& bucket = table[index];
    bucket.remove_if([&](const std::pair<T, U>& element) {
        if (element.second == val.second) {
            --elemCount;
            return true;
        }
        return false;
    });
}

template <typename T, typename U>
bool Hashtable<T, U>::isPrime(std::size_t val) {
    if (val <= 1) {
        return false;
    }
    if (val <= 3) {
        return true;
    }
    if (val % 2 == 0 || val % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= val; i += 6) {
        if (val % i == 0 || val % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

template <typename T, typename U>
std::size_t Hashtable<T, U>::nextPrime() {
    std::size_t prime = table.capacity();
    bool flag = false;
    while (!flag) {
        ++prime;
        if (isPrime(prime)) {
            flag = true;
        }
    }
    return prime;
}
