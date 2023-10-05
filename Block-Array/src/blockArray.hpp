#ifndef BLOCK_ARRAY_
#define BLOCK_ARRAY_

#include <vector>
#include <stdexcept>

template <typename T, std::size_t s>
class BlockArray {
public:
    BlockArray();
    ~BlockArray() noexcept;
    constexpr std::size_t size() noexcept;
    void insert(std::size_t index, const T& value);
    void erase(std::size_t index);
    T& operator[](std::size_t index);   
private:
    std::vector<std::vector<T>> blocks;
};

#include "blockArray.tpp"
#endif  //BLOCK_ARRAY_