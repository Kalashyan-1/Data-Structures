#include "gTree.h"

int sum(int n) {return n +2;}
int square(int n) {return n*n;}
int divide(int n) {return n / 2;}
int add(int n) {return n + n;}

int main() {
    std::function<int(int)> func = sum;
    GTree tree;
    tree.insert(sum, 0, 0);
    tree.insert(square, 1, 5);
    tree.insert(divide, 2, 5);
    tree.insert(add, 3, 5);
    std::cout << tree.exec(1);
}