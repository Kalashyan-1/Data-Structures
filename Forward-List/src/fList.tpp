#include "fList.hpp"
template <typename T>
FList<T>::FList() : head {nullptr}, size {0}
{
}

template <typename T>
FList<T>::~FList() {
    if (head) {
        Node* tmp;
        while (head) {   
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
}

template <typename T>
void FList<T>::insert(T n, std::size_t index) { 
    if (index > size) {
		throw std::invalid_argument("Invalid index");
    }
    ++size;
    Node* newNode = new Node(n);
    if (!head) {
        head = newNode;
        return;
    }
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* tmp = head;
        while (--index){
            tmp = tmp->next;
        }
        Node* tmp2 = tmp->next;
        tmp->next = newNode;
        tmp->next->next = tmp2;
    }
}

template <typename T>
void FList<T>::erase(int val) {
    if (!head) {return;}
    Node* tmp = head;
    if (tmp->data == val) {
        head = head->next;
        delete tmp;
        --size;
        return;
    }
    while (tmp->next) {
        if (tmp->next->data == val) {
            Node* tmp2 = tmp->next->next;
            delete tmp->next;
            tmp->next = tmp2;
            --size;
            break;
        }
        tmp = tmp->next;
    }
    
}
template <typename U>
void merge(FList<U>& l1, FList<U>& l2) {
    auto n1 = l1.head;
    auto n2 = l2.head;
    auto tmp2 = n1;
    while (n1 && n2) {
        tmp2 = n1;
        if (n1->data <= n2->data) {
            n1 = n1->next;
        } else {
            auto tmp = n1->next->next;
            n1->next = n2;
            n2 = n2->next;
            n1 = n1->next;
            n1->next = tmp;
        }
    }

    if (n2) {
        tmp2->next = n2;
    }
    l1.size += l2.size;
    l2.head = nullptr;
    l2.size = 0;
}

template <typename T>
void FList<T>::print() {
    Node* tmp = head;
    while (tmp) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

template <typename U>
void swap(FList<U>& l1, FList<U>& l2) {
    std::swap(l1.head, l2.head);
    std::swap(l1.size, l2.size);
}

template <typename T>
std::pair<FList<T>, FList<T>> FList<T>::split() {
    if (!head) {return {}};
    
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    fast = slow->next;
    slow->next = nullptr;

    return ({head, slow->next});
}

template <typename T>
void FList<T>::push_front(T& val) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void FList<T>::push_front(T&& val) {
    Node* newNode = new Node(std::move(val));
    newNode->next = head;
    head = newNode;
}

template <typename T>
void FList<T>::pop_front() {
    if (!head) return;
    Node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
}