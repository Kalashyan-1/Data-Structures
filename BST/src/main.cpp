#include "bst.hpp"

int main() {
    BST<int> tree;

// TEST
    // tree.insert(5);
    // tree.insert(7);
    // tree.insert(3);
    // tree.insert(2);
    // tree.insert(4);
    // tree.insert(6);
    // tree.insert(8);
    // tree.remove(5);
    // std::cout << tree.find(5) << std::endl;
    // std::cout << tree.height() << std::endl;
    // tree.inorder();
    // std::cout << std::endl;
    // tree.postorder();
    // std::cout << std::endl;
    // tree.insert(4);
    // tree.insert(5);
    // tree.insert(2);
    // tree.insert(3);
    // // tree.preorder();
    // std::cout << std::endl;
    // tree.levelorder();
    // std::cout << std::endl;

    // tree.save("tree.txt");

    // BST<int> tree2;
    // tree2.load("tree.txt");

    // tree2.inorder();
    // std::cout << std::endl;
    // tree2.postorder();
    // std::cout << std::endl;
    // tree2.preorder();
    // std::cout << std::endl;
    // tree2.levelorder();
    // std::cout << std::endl;

    tree.insert(20);
    tree.insert(9);
    tree.insert(10);
    tree.insert(8);
    tree.insert(7);
    tree.insert(6);
    tree.insert(9);
    tree.insert(9);
    tree.insert(9);

    tree.insert(30);
    tree.insert(35);
    tree.insert(40);
    tree.insert(36);
    tree.insert(37);
    tree.insert(38);

    // tree.inorder();
    tree.printPredAndSucc(38);
}