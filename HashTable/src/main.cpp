#include <iostream>
#include "hashtable.hpp"

struct ST {
    int i = 5;
    std::string str = "KKK";
    friend std::ostream& operator<<(std::ostream& stream, ST& obj) {
        stream << obj.i << " " << obj.str;
        return stream;
    }
};

int main() {
    Hashtable<std::string, int> h;
    h.insert({"a", 4});
    h["p"] = 55;
    h.erase({"p", 4});
    std::cout << h["a"] << std::endl;

    Hashtable<int, ST> h2;
    ST s;
    h2[5] = s;
    std::cout << h2[5] << std::endl;
}