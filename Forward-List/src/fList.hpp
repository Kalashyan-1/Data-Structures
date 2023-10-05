#ifndef FORWARD_LIST_
#define FORWARD_LIST_

#include <iostream>
#include <stdexcept>


template <typename T>
class FList {

struct Node {
		Node* next;
		T data;
        Node(T n) : next{nullptr}, data{n}{}
};
	
public:
	FList();
	~FList();
	void insert(T n, std::size_t index);
	void erase(int n);
	void push_front(T&);
	void push_front(T&&);
	void pop_front();
	void print();

    template <typename U>
	friend void merge(FList<U>&, FList<U>&);

    template <typename U>
	friend void swap(FList<U>&, FList<U>&);

private:
	Node* head;
	std::size_t size;
};

#include "fList.tpp"

#endif //FORWARD_LIST_