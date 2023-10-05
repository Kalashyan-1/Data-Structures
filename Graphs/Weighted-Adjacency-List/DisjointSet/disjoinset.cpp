#include "disjointSet.hpp"

DisjointSet::DisjointSet(std::size_t s) : parent(s), size(s, 0) {
    for (int i = 0; i < s; ++i) {
        parent[i] = i;
    }
}

DisjointSet::~DisjointSet()noexcept {}

int DisjointSet::findSetRoot(int x) {
    int par = parent[x];
    if (x == par) {
        return x;
    }
    parent[x] = findSetRoot(par);    // path compression
    return parent[x];
}

void DisjointSet::unify(int x, int y) {
    if (x >= parent.size() || y >= parent.size()) {
        throw std::invalid_argument("Invalid argument");
    }
    
    int root1 = findSetRoot(x);
    int root2 = findSetRoot(y);
    if (root1 == root2) return; // Already part of the same set

    if (size[root1] < size[root2]) {
        parent[root1] = root2;
        size[root2] += size[root1];
    } else {
        parent[root2] = root1;
        size[root1] += size[root2];
    }

}