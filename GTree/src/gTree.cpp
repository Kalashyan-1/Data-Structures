#include "gTree.h"

void GTree::insert(std::function<int(int)> value, int level, int position) {
    if (level < 0 || level > height()) {throw std::invalid_argument("Given level is invalid");}
    if (!this->head) {
        head = new Node(value);
        return;
    }
    std::queue<Node*> qu;
    Node* tmp = nullptr;
    int nodeCount;
    qu.push(head);
    for (int i = 0; i < level - 1; ++i) {
        nodeCount = qu.size();
        while (nodeCount) {
            tmp = qu.front();
            qu.pop();
            for (auto& child : tmp->children) {
                qu.push(child);
            }
            --nodeCount;
        }
    }
    Node* newNode = new Node(value);
    if (position < 0 || position > qu.front()->children.size()) {
        qu.front()->children.push_back(newNode);
    } else {
        auto it = qu.front()->children.begin() + position;
        qu.front()->children.insert(it, newNode);
    }
}

int GTree::exec(int number) {
    if (!head){return 0;}
    std::queue<Node*> qu;
    Node* tmp = nullptr;
    qu.push(head);
    while (!qu.empty()) {
        tmp = qu.front();
        qu.pop();
        number = tmp->val(number);
        for (auto child : tmp->children) {
            qu.push(child);
        }
    }
    return number;
}

int GTree::height() {
    if (!head) {return 0;}
    std::queue<Node*> qu;
    Node* tmp = nullptr;
    int height = 0;
    int nodeCount;
    qu.push(head);
    while (!qu.empty()) {
        nodeCount = qu.size();
        while (nodeCount) {
            tmp = qu.front();
            qu.pop();
            for (auto a : tmp->children) {
                qu.push(a);
            }
            --nodeCount;
        }
       ++height;
    }
    return height;
}
