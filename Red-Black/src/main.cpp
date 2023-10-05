#include "rbTree.hpp"

int main() {
    RBTree<int> tree;
    // tree.insert(10);
    // tree.insert(18);
    // tree.insert(7);
    // tree.insert(15);
    // tree.insert(16);
    // tree.insert(30);
    // tree.insert(25);
    // tree.insert(40);
    // tree.insert(60);
    // tree.insert(2);
    // tree.insert(1);
    // tree.insert(70);

    // tree.remove(10);
    // tree.remove(30);

    tree.insert(41);
    tree.insert(38);
    tree.insert(31);
    tree.insert(12);
    tree.insert(19);
    tree.insert(8);

    tree.remove(8);
    tree.remove(12);
    // tree.remove(19);
    // tree.remove(38);
    // tree.remove(41);
    // tree.remove(31);


    tree.levelOrder();
    // tree.inorder();
}