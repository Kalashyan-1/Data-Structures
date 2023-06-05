#include "avl.hpp"

template <typename T>
void AVL<T>::insert(T val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    std::stack<Node*> st;
    Node* tmp = root;
    Node* tmp2 = nullptr;
    bool isLeftChild = false;

    while (tmp && val != tmp->data) {
        tmp2 = tmp;
        if (val < tmp->data) {
            st.push(tmp);
            tmp = tmp->left;
            isLeftChild = true;
        } else {
            st.push(tmp);
            tmp = tmp->right;
            isLeftChild = false;
        }
    }
    if (!tmp) {
        if (val < tmp2->data) {
            tmp2->left = new Node(val);
        } else {
            tmp2->right = new Node(val);
        }
    } else {
        return;
    }
    balanceTree(val, st);
}

template <typename T>
void AVL<T>::remove(T val) {
    if (!root) {return;}
    Node* tmp = root;
    Node* tmp2 = nullptr;
    std::stack<Node*> st;

    while (tmp && val != tmp->data) {
        tmp2 = tmp;
        st.push(tmp);
        if (val < tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }

    if (!tmp) {
        return;
    }

    if (!tmp->left && !tmp->right) {
        if (tmp != root) {
            if (tmp2->left == tmp) {
                tmp2->left = nullptr;
            } else {
                tmp2->right = nullptr;
            }
        } else {
            root = nullptr;
        }
        delete tmp;
    } else if (!tmp->left) {
        Node* tmp3 = tmp;
        tmp = tmp->right;
        if (tmp3 != root) {
            if (tmp2->left == tmp3) {
                tmp2->left = tmp;
            } else {
                tmp2->right = tmp;
            }
        } else {
            root = tmp;
        }
        delete tmp3;
    } else if (!tmp->right) {
        Node* tmp3 = tmp;
        tmp = tmp->left;
        if (tmp3 != root) {
            if (tmp2->left == tmp3) {
                tmp2->left = tmp;
            } else {
                tmp2->right = tmp;
            }
        } else {
            root = tmp;
        }
        delete tmp3;
    } else {
        Node* tmp3 = tmp;
        Node* tmp4 = tmp->right;

        while (tmp4->left) {
            tmp3 = tmp4;
            tmp4 = tmp4->left;
        }

        if (tmp3 != tmp) {
            tmp3->left = tmp4->right;
            tmp4->right = tmp->right;
        }
        tmp4->left = tmp->left;

        if (tmp != root) {
            if (tmp2->left == tmp) {
                tmp2->left = tmp4;
            } else {
                tmp2->right = tmp4;
            }
        } else {
            root = tmp4;
        }
        delete tmp;
    }
    balanceTree(val, st);    
}


template <typename T>
void AVL<T>::balanceTree(T val, std::stack<Node*>& st) {
    Node* tmp = nullptr;
    while (!st.empty()) {
        tmp = st.top();
        st.pop();
        
        tmp->height = 1 + std::max(getheight(tmp->left), getheight(tmp->right));

        int balance = getheight(tmp->left) - getheight(tmp->right);

        // LL
        if (balance > 1 && val < tmp->left->data) {
            tmp = rightRotate(tmp);
        }
        // RR
        else if (balance < -1 && val > tmp->right->data) {
            tmp = leftRotate(tmp);
        }

        // LR
        else if (balance > 1 && val > tmp->left->data) {
            tmp->left = leftRotate(tmp->left);
            tmp = rightRotate(tmp);
        } 

        // RL
        else if (balance < -1 && val < tmp->right->data) {
            tmp->right = rightRotate(tmp->right);
            tmp = leftRotate(tmp);
        }

        if (st.empty()) {
            root = tmp;
        } else {
            Node* parent = st.top();
            if (val < parent->data) {
                parent->left = tmp;
            } else {
                parent->right = tmp;
            }
        }
    }
}


template <typename T> 
typename AVL<T>::Node* AVL<T>::rightRotate(Node* node) {
    Node* newNode = node->left;
    Node* tmp = newNode->right;

    node->left = tmp;
    newNode->right = node;

    node->height = 1 + std::max(getheight(node->left), getheight(node->right));
    newNode->height = 1 + std::max(getheight(newNode->left), getheight(newNode->right));
    return newNode;
}

template <typename T> 
typename AVL<T>::Node* AVL<T>::leftRotate(Node* node) {
    Node* newNode = node->right;
    Node* tmp = newNode->left;

    node->right = tmp;
    newNode->left = node;

    node->height = 1 + std::max(getheight(node->left), getheight(node->right));
    newNode->height = 1 + std::max(getheight(newNode->left), getheight(newNode->right));
    return newNode;
}


template <typename T> 
int AVL<T>::getheight(Node* node) {
    if (!node) {
        return 0;
    }
    return node->height;
}

template <typename T> 
void AVL<T>::levelOrder() {
    if (!root) {return;}
    Node* tmp = nullptr;
    std::queue<Node*> qu;
    qu.push(root);
    while (!qu.empty()) {
        tmp = qu.front();
        qu.pop();
        std::cout << tmp->data << " ";
        if (tmp->left) {
            qu.push(tmp->left);
        }
        if (tmp->right) {
            qu.push(tmp->right);
        }
    }
}

template <typename T>
int AVL<T>::height() {
    return root->height;
}

template <typename T>
bool AVL<T>::find(T val) {
    if (!root) {
        return false;
    }
    Node* tmp = root;
    while (tmp) {
        if (tmp->data == val) {
            return true;
        }
        if (val < tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return false;
}

template <typename T>
void AVL<T>::inorder() {
    if (!root) {return;}
    Node* tmp = root;
    Node* tmp2 = nullptr;
    while (tmp) {
        if (!tmp->left) {
            std::cout << tmp->data;
            tmp = tmp->right;
        } else {
            tmp2 = tmp->left;
            while (tmp2->right && tmp2->right != tmp) {
                tmp2 = tmp2->right;
            }

            if (!tmp2->right) {
                tmp2->right = tmp;
                tmp = tmp->left;
            } else {
                std::cout << tmp2->right->data;
                tmp2->right = nullptr;
                tmp = tmp->right;
            }
        }
    }
}

template <typename T>
void AVL<T>::postorder() {
    if (!root) {return;}
    std::stack<Node*> st;
    Node* tmp1 = root;
    Node* tmp2 = nullptr;
    Node* tmp3 = nullptr;
    while (tmp1 || !st.empty()) {
        if (tmp1) {
            st.push(tmp1);
            tmp1 = tmp1->left;
        } else {
            tmp3 = st.top();
            if (tmp3->right && tmp2 != tmp3->right) {
                tmp1 = tmp3->right;
            } else {
                std::cout << tmp3->data;
                tmp2 = tmp3;
                st.pop();
            }
        }
    }
} 

template <typename T>
void AVL<T>::preorder() {
    if (!root) {return;}
    Node* tmp = root;
    Node* tmp2 = nullptr;
    while (tmp) {
        if (!tmp->left) {
            std::cout << tmp->data;
            tmp = tmp->right;
        } else {
            tmp2 = tmp->left;
            while (tmp2->right && tmp2->right != tmp) {
                tmp2 = tmp2->right;
            }
            if (!tmp2->right) {
                tmp2->right = tmp;
                std::cout << tmp->data;
                tmp = tmp->left;
            } else {
                tmp2->right = nullptr;
                tmp = tmp->right;
            }
        }
    }
}
