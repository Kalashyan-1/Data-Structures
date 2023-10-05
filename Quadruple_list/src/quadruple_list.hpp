#ifndef QUAD_LIST_HPP_
#define QUAD_LIST_HPP_

#include <iostream>
#include <stdexcept>
namespace ql
{
enum class Order {
    Inserted,
    Increasing,
    Decreasing
};


template <typename T>
class Quadruple_list{
private:
    struct Node{
        Node* next;
        Node* prev;
        Node* incNext;
        Node* decNext;
        T data;

        Node(): next{nullptr}, prev{nullptr}, incNext{nullptr}, decNext{nullptr} { }
        Node(T val) : next{nullptr}, prev{nullptr}, incNext{nullptr}, decNext{nullptr}, data{val} {}
    };
    
    Node* head = nullptr;
    Node* inc = nullptr;
    Node* dec = nullptr;
public:
    void insert(T val);
    void erase(int index);
    void print(Order order) const;
};

#include "quadruple_list.tpp"
} // namespace ql

#endif  //QUAD_LIST_HPP_ 
