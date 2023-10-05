#ifndef BST_HPP_
#define BST_HPP_

#include <queue>
#include <stack>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>

// This struct just for recursive functions
// template <typename T>
// struct TreeNode {
//     T val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(T x) : val(x), left(NULL), right(NULL) {}
// };
 

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) :data{value}, left {nullptr}, right {nullptr} {}
    };
    Node* root;
public:
    BST() = default;
    ~BST() noexcept;
public:
   void insert(T value);
   void remove(T value);
   bool find(T value);
   int height();
   void inorder();
   void postorder();
   void preorder();
   void levelorder();
   void printPredAndSucc(T);

private:
   void deleteTree(Node*);
   Node* getMax(Node*);
   Node* getMin(Node*);
   Node* predecessor(Node*);
   Node* successor(Node*);
};

#include "bst.tpp"


#endif  //BST_HPP_
