#ifndef AVL_
#define AVL_

#include <iostream>
#include <queue>
#include <stack>


template <typename T>
class AVL {
private:
    struct Node {
        int height;
        T data;
        Node* left;
        Node* right;
        Node() : left{nullptr}, right {nullptr}, height{0} {}
        Node(T val) : left{nullptr} , right {nullptr}, data {val}, height {1} {}
    };
    
    Node* root = nullptr;
private:
    int getheight(Node*);
    typename AVL<T>::Node* leftRotate(Node*);
    typename AVL<T>::Node* rightRotate(Node*);
    void balanceTree(T val, std::stack<Node*>& st);
public:
    void insert(T val);
    void remove(T val);
    bool find(T value);
    int height();
    void inorder();
    void postorder();
    void preorder();
    void levelOrder();};

#include "avl.tpp"

#endif  //AVL_