#ifndef GTREE_
#define GTREE_

#include <iostream>
#include <functional>
#include <queue>    
#include <stdexcept>

class GTree {
    struct Node {
        std::function<int(int)> val;
        std::vector<Node*> children;
        Node(std::function<int(int)> v) : val {v}{}
    };
private:
    Node* head;
public:
    void insert(std::function<int(int)>, int level, int pos);
    int exec(int num);    
    int height();
};

#endif //GTREE_