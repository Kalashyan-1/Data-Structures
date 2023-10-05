#include "threadPool.h"
// template <typename... Args>
void foo(int a) {
    std::cout << "Done" << std::endl;
}

int main() {
    ThreadPool tr(3);
    for (int i = 0; i < 5; ++i) {
        tr.addThread(foo, i);
    }
}