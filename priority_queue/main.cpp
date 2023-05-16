#include "priority_queue.hpp"
#include <vector>
#include <iostream>
#include <queue>

struct S 
{
    int id;
 
    S(int i, double d, std::string s) : id{i}
    {
        std::cout << "S::S(" << i << ", " << d << ", \"" << s << "\");\n";
    }
 
    friend bool operator< (S const& x, S const& y) { return x.id < y.id; }
};


int main () {
    Priority_queue<S> queue1;
    queue1.emplace(42, 3.14, "C++");
    std::cout << "id: " << queue1.top().id << '\n';

    std::vector<int> vec {2, 7, 9, 2 ,3, 4};
    Priority_queue<int> queue2(std::less<int>(), vec);
    std::cout << queue2.top();
    queue2.pop();
    queue2.push(20);
    queue2.emplace(10);
    std::cout << queue2.top();

    Priority_queue<int> queue3(std::less<int>(), vec);
    queue2.swap(queue3);
}