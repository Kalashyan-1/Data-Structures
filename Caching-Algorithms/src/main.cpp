#include "LRU.hpp"
#include "MRU.hpp"
#include "LFU.hpp"

int main() {
    // LRU<int> cach(3);
    // cach.put( -1, 1);
    // cach.put( -2, 2);
    // cach.put(-3, 3);
    // cach.put(-4, 4);
    // std::cout << cach.get(-4);


    // MRU<int> cach(3);
    // cach.put( -1, 1);
    // cach.put( -2, 2);
    // cach.put(-3, 3);
    // cach.put(-4, 4);
    // std::cout << cach.get(-4);

    LFU<int> cach(3);
    cach.put( -1, 1);
    cach.put( -2, 2);
    cach.put(-3, 3);
    cach.put(-4, 4);
    std::cout << cach.get(-1);
}