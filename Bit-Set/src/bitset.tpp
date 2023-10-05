#ifndef BITSET_TPP_
#define BITSET_TPP_

#include "bitset.hpp"

template <std::size_t N>
Bitset<N>::Bitset() {
    data = std::vector<bool>(N, false);
}

template <std::size_t N>
constexpr Bitset<N>& Bitset<N>::set() noexcept {
    for (std::size_t i = 0; i < N; ++i) {
        data[i] = true;
    }
    return *this;
}

template <std::size_t N>
constexpr Bitset<N>& Bitset<N>::set(std::size_t pos) {
    if (pos < N) {
        data[pos] = true;
    }
    return *this;
}

template <std::size_t N>
constexpr Bitset<N>& Bitset<N>::reset() noexcept {
    for (std::size_t i = 0; i < N; ++i) {
        data[i] = false;
    }
    return *this;
}

template <std::size_t N>
constexpr Bitset<N>& Bitset<N>::reset(std::size_t pos) {
    if (pos < N) {
        data[pos] = false;
    }
    return *this;
}

template <std::size_t N>
constexpr bool Bitset<N>::all() const noexcept {
    for (std::size_t i = 0; i < N; ++i) {
        if (!data[i]) {
            return false;
        }
    }
    return true;
}

template <std::size_t N>
constexpr bool Bitset<N>::any() const noexcept {
    for (std::size_t i = 0; i < N; ++i) {
        if (data[i]) {
            return true;
        }
    }
    return false;
}

template <std::size_t N>
constexpr bool Bitset<N>::none() const noexcept {
    return !any();
}

template <std::size_t N>
bool Bitset<N>::operator[](std::size_t pos) {
    if (pos < N) {
        return data[pos];
    }
    return false;
}

template <std::size_t T>
std::ostream& operator<<(std::ostream& stream, const Bitset<T>& bitset) {
    for (std::size_t i = 0; i < T; ++i) {
        stream << bitset.data[i];
    }
    return stream;
}

#endif  // BITSET_TPP_
