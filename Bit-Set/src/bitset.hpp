#ifndef BITSET_
#define BITSET_

#include <iostream>
#include <vector>

template <std::size_t N>
class Bitset {
public:
    Bitset();
    ~Bitset() = default;

    constexpr Bitset& set() noexcept;
    constexpr Bitset& set(std::size_t pos);

    constexpr Bitset& reset() noexcept;
    constexpr Bitset& reset(std::size_t pos);

    constexpr bool all() const noexcept;
    constexpr bool any() const noexcept;
    constexpr bool none() const noexcept;

    bool operator[](std::size_t pos);
    template <std::size_t T>
    friend std::ostream& operator<<(std::ostream& stream, const Bitset<T>& bitset);
private:
    std::vector<bool> data;
};

#include "bitset.tpp"

#endif  //BITSET_