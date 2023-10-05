#include "queue.hpp"

int main() {
    Queue<int> qu;
    int m = 5;
    qu.push(m);
    qu.emplace(5);
    qu.front();
}