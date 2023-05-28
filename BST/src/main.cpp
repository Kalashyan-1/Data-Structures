#include "bst.hpp"

int main() {
    BST<int> tree;
    tree.insert(5);
    tree.insert(7);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.remove(5);
    std::cout << tree.find(5) << std::endl;
    std::cout << tree.height() << std::endl;
    tree.inorder();
    std::cout << std::endl;
    tree.postorder();
    std::cout << std::endl;
    tree.preorder();
    std::cout << std::endl;
    tree.levelorder();
    std::cout << std::endl;

    tree.save("tree.txt");

    BST<int> tree2;
    tree2.load("tree.txt");

    tree2.inorder();
    std::cout << std::endl;
    tree2.postorder();
    std::cout << std::endl;
    tree2.preorder();
    std::cout << std::endl;
    tree2.levelorder();
    std::cout << std::endl;
}