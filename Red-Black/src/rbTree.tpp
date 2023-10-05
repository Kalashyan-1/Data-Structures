#include "rbTree.hpp"

template <typename T>
RBTree<T>::RBTree() {
    NIL = new Node;
    NIL->color = BLACK;
    root = NIL;
}


template <typename T> 
void RBTree<T>::insert(T z) {
  Node* newNode = new Node(z);
  Node* x = root;
  Node* y = NIL;
  
  while (x != NIL) {
    y = x;
    if (newNode->data < x->data) {
      x = x->left;
    } else if (newNode->data > x->data){
      x = x->right;
    } else {
      return;
    }
  }

  newNode->parent = y;
  if (y == NIL) {
    root = newNode;
  } else if (newNode->data < y->data) {
    y->left = newNode;
  } else {
    y->right = newNode;
  }
  newNode->left = NIL;
  newNode->right = NIL;
  fixVoilation(newNode);
}


template <typename T>
void RBTree<T>::leftRotate(Node* y) {
  Node* x = y->right;
  y->right = x->left;

  if (x->left != NIL) {
    x->left->parent = y;
  }

  x->parent = y->parent;
  if (y->parent == NIL) {
    root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }

  x->left = y;
  y->parent = x;
}


template <typename T>
void RBTree<T>::rightRotate(Node* y) {
  Node* x = y->left;
  y->left = x->right;

  if (x->right != NIL) {
    x->right->parent = y;
  }

  x->parent = y->parent;

  if (y->parent == NIL) {
    root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }

  x->right = y;
  y->parent = x;
}


template <typename T>
void RBTree<T>::fixVoilation(Node* z) {
  Node* uncle;
  while (z->parent->color == RED) {
    if (z->parent == z->parent->parent->left) {
      uncle = z->parent->parent->right;

      if (uncle->color == RED) {
        z->parent->color = BLACK;
        uncle->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          leftRotate(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        rightRotate(z->parent->parent);
      }
    } else {
      uncle = z->parent->left;
      if (uncle->color == RED) {
        z->color = BLACK;
        uncle->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z = z->parent->left) {
          z = z->parent;
          rightRotate(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        leftRotate(z->parent->parent);
      }
    }
  }
  root->color = BLACK;
}


template <typename T>
void RBTree<T>::transplant(Node* u, Node* v) {
    if (u->parent == NIL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template <typename T>
void RBTree<T>::remove(T v) {
    if (root == NIL) {
        return;
    }
    Node* z = root;
    while (z != NIL && z->data != v) {
        if (v < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    } 
    if (z == NIL) {return;}

    Node* y = z;
    Color yOrgColor = y->color;
    Node* x;
    if (z->left == NIL) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(y->right);
        yOrgColor = y->color;
        x = y->right;

        if (y != y->right) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        } else {
            x->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;        
    }

    if (yOrgColor == BLACK) {
        fixdoubleBlack(x);
    }
}

template <typename T>
void RBTree<T>::fixdoubleBlack(Node* x) {
    Node* w;
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
        
            if (w->color == RED) {
                w->color = BLACK;
                w->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                w->right->color = BLACK;
                x->parent->color = BLACK;
                rightRotate(w->parent);

                x = root;
            }
        } else {
            w = x->parent->left;

            if (w->color == RED) {
                w->color = BLACK;
                w->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = RED;
                    w->color = BLACK;
                    leftRotate(x->parent);
                    w = x->parent->left;
                } 

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);

                root = x;
            }
        }
    }  
    x->color = BLACK; 
}

template <typename T>
typename RBTree<T>::Node* RBTree<T>::minimum(Node* node) {
    while (node->left != NIL) {
      node = node->left;
    }
    return node;
  }


template <typename T>
typename RBTree<T>::Node* RBTree<T>::searchNode(T value) {
    Node* current = root;
    while (current != NIL) {
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return current; 
        }
    }   
    return nullptr; 
}


template <typename T> 
void RBTree<T>::inorder() {
    if (!root) {return;}
    Node* tmp = root;
    Node* tmp2 = nullptr;
    while (tmp != NIL) {
        if (tmp->left == NIL) {
            std::cout << tmp->data << " ";
            tmp = tmp->right;
        } else {
            tmp2 = tmp->left;
            while (tmp && tmp2->right != NIL && tmp2->right != tmp) {
                tmp2 = tmp2->right;
            }

            if (tmp2->right == NIL) {
                tmp2->right = tmp;
                tmp = tmp->left;
            } else {
                std::cout << tmp2->right->data << " ";
                tmp2->right = NIL;
                tmp = tmp->right;
            }
        }
    }
}


template <typename T>
void RBTree<T>::levelOrder() {
    if (root == NIL) {
        return;
    }
    std::queue<Node*> qu;
    qu.push(root);
    Node* tmp = nullptr;
    while (!qu.empty()) {
        tmp = qu.front();
        qu.pop();

        std::cout << tmp->data << ((tmp->color == RED)? "red" : "black") << " ";
        if (tmp->left != NIL) {
            qu.push(tmp->left);
        }
        if (tmp->right != NIL) {
            qu.push(tmp->right);
        }
    }
}

