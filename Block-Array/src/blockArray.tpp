#include "blockArray.hpp"
template <typename T, std::size_t s>
BlockArray<T, s>::BlockArray() {
    blocks.push_back(std::vector<T>(s));
}

template <typename T, std::size_t s>
BlockArray<T, s>::~BlockArray() noexcept {}

template <typename T, std::size_t s>
T& BlockArray<T, s>::operator[](std::size_t index) {
    size_t blockIndex = index / s;
    size_t elementIndex = index % s;
    if (blockIndex >= blocks.size()) {
        throw std::invalid_argument("Given index is grather then s of array");
    }
    return blocks[blockIndex][elementIndex];
}

template <typename T, std::size_t s>
void BlockArray<T, s>::insert(std::size_t index, const T& value) {
    size_t blockIndex = index / s;
    size_t elementIndex = index % s;

    if (blockIndex >= blocks.size()) {
        blocks.push_back(std::vector<T>(s));
    }
    blocks[blockIndex].insert(blocks[blockIndex].begin() + elementIndex, value);
}

template <typename T, std::size_t s>
void BlockArray<T, s>::erase(std::size_t index) {
    size_t blockIndex = index / s;
    size_t elementIndex = index % s;
    if (blockIndex < blocks.size()) {
        blocks[blockIndex].erase(blocks[blockIndex].begin() + elementIndex);
    }
}

template <typename T, std::size_t s>
constexpr std::size_t BlockArray<T, s>::size() noexcept {
    return blocks.size() * s;
}
