#ifndef QUAD_LIST_TPP_
#define QUAD_LIST_TPP_

#include "quadruple_list.hpp"


template <typename T>
void ql::Quadruple_list<T>::insert(T val) {
    if (!head) {
        head = new Node(val);
        inc = head;
        dec = head;
        return;
    }
    Node* tmp = head;
    Node* increasing = nullptr;
    Node* decreasing = nullptr;
    T minVal = val;
    T maxVal = val;
    while (tmp) {
        if (tmp->data == val) {
            throw std::invalid_argument("Given argument alredy exist in list");
        }
        if (minVal > tmp->data) {
            if (!increasing || (increasing->data < tmp->data)) {
             increasing = tmp;
            } 
        }

        if (maxVal < tmp->data) {
             if (!decreasing || (decreasing->data > tmp->data)) {
             decreasing = tmp;
            } 
        }
        if (!tmp->next) {
            tmp->next = new Node(val);
            tmp->next->prev = tmp;
            break;
        }
        tmp = tmp->next;
    }
   
    tmp = tmp->next;

    if (!increasing) {
        tmp->incNext = inc;
        inc = tmp;
    } else {
        
        tmp->incNext = increasing->incNext;
        increasing->incNext = tmp;
    }

    if (!decreasing) {
        tmp->decNext = dec;
        dec = tmp;
    } else {
        tmp->decNext = decreasing->decNext;
        decreasing->decNext = tmp;
    }
    
}

template <typename T>
void ql::Quadruple_list<T>::erase(int index) {
    if (!head) {return;}
    if (index <  0) {
        throw std::out_of_range("Invalid index < 0");
    }
    Node* tmp;
    if (index == 0) {
        tmp = new Node();
        tmp->next = head;
        head->prev = tmp;
    } else {
        tmp = head;
    }
    --index;
    Node* current = nullptr;
    Node* increasing = inc;
    Node* decreasing = dec;
    while (index > 0 && tmp) {
        tmp = tmp->next;
        --index;
    }
    if (!tmp || !tmp->next) {
        throw std::out_of_range("Invalid index");
    }
    if (tmp == head && tmp == inc && index == -1) {
        inc = inc->incNext;
    } else if (tmp->next == inc) {
        inc = inc->incNext; 
    } else {
        current =  tmp->next;
        while (increasing->incNext->data != current->data) {
            increasing = increasing->incNext;
        }
        increasing->incNext = current->incNext;
    }

    if (tmp == head && tmp == dec && index == -1) {
        dec = dec->decNext;
    } else if (tmp->next == dec) {
        dec = dec->decNext;
    } else {
        current =  tmp->next;
        while (decreasing->decNext->data != current->data) {
            decreasing = decreasing->decNext;
        }
        decreasing->decNext = current->decNext;
    }

    if (tmp->next == head) {
        if (!tmp->next->next) {
            delete tmp->next;
            delete tmp;
            head = nullptr;
        } else {
            head = head->next;
            tmp = tmp->next;
            delete tmp->prev;
            delete head->prev;
            head->prev = nullptr;
        }
    } else {
        if (!tmp->next->next) {
            delete tmp->next;
            tmp->next = nullptr;
        } else {
            tmp->next = tmp->next->next;
            delete tmp->next->prev;
            tmp->next->prev = tmp;
        }
    }
}

template <typename T>
void ql::Quadruple_list<T>::print(Order ord) const {
    Node* tmp;
    switch (ord)
    {
    case Order::Inserted:
    tmp = head;
        while (tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
        break;
    case Order::Increasing:
    tmp = inc;
        while (tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->incNext;
        }
        std::cout << std::endl;
    break;
    case Order::Decreasing:
        tmp = dec;
        while (tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->decNext;
        }
        std::cout << std::endl;
    break;
    }
}

#endif    // QUAD_LIST_TPP_