#include "quadruple_list.hpp"

int main() {
    ql::Quadruple_list<int> list;
    list.insert(7);
    list.insert(1);
    list.insert(8);
    list.insert(9);
    list.insert(2);
    list.insert(4);

    // list.erase(0);
    // list.erase(1);
    // list.erase(0);
    // list.erase(1);
    // list.erase(1);
    // list.erase(0);
    
    list.print(ql::Order::Inserted);
    list.print(ql::Order::Increasing);
    list.print(ql::Order::Decreasing);
}