#ifndef HASH_
#define HASH_
#include <vector>
#include <string>
#include <list>
#include <algorithm>

#define Initil_Cap 17
#define Threshold 0.65

template <typename T, typename U>
class Hashtable {
public:
    Hashtable() : table(Initil_Cap), elemCount{0} {}
    ~Hashtable() = default;

public:
    void insert(const std::pair<T, U>&);
    void erase(const std::pair<T, U> val);
    U& operator[](T);

private:
    int hash(T);
    void resize(std::size_t newSize);
    [[nodiscard]] bool isPrime(std::size_t);
    std::size_t nextPrime();

private:
    std::vector<std::list<std::pair<T, U>>> table;
    std::size_t elemCount;
};

#include "hashtable.tpp"
#endif   //HASH_
