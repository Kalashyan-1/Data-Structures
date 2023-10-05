#ifndef RB_TREE_
#define RB_TREE_

#include <stack>
#include <queue>
#include <iostream>

template <typename T>
class RBTree {
private:
    enum Color {
         BLACK,
         RED
    };
    struct Node {
        Color color;
        Node* left;
        Node* right;
        Node* parent;
        T data;
        Node() : color {RED}, left {nullptr}, right {nullptr}, parent {nullptr}, data {0} {}
        Node(T val) : color {RED}, left {nullptr}, right {nullptr}, parent {nullptr}, data {val}{}
        ~Node() {left = nullptr; right = nullptr; parent = nullptr;}
    };
    Node* root;
    Node* NIL;
    
private:
    void fixVoilation(Node*);
    void leftRotate(Node*);
    void rightRotate(Node*);
    void fixdoubleBlack(Node*);
    void transplant(Node*, Node*);
    typename RBTree<T>::Node* minimum(Node*);
    typename RBTree<T>::Node* searchNode(T value);

public:
    RBTree();
    void insert(T val);
    void remove(T val);
    void levelOrder();
    void inorder();
};

#include "rbTree.tpp"
#endif  //RBTree 
