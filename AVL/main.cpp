#include "avl.hpp"

int main() {
    AVL<int> avl;
    avl.insert(5);
    avl.insert(4);
    avl.insert(2);
    avl.insert(9);
    avl.insert(8);
    avl.insert(10);
    avl.remove(2);
    avl.levelOrder();
    std::cout << std::endl;
    avl.inorder();
    std::cout << std::endl;
    avl.postorder();
    std::cout << std::endl;
    avl.preorder();
}