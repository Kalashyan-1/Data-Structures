#include "bitset.hpp"

int main() {
    Bitset<6> m;
    m.set(5);
    m.all();
    m.any();
    m.none();
    std::cout << m[5];
}
