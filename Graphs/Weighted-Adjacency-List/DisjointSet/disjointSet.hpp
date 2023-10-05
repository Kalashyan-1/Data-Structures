#ifndef DIS_SET_HPP_
#define DIS_SET_HPP_

#include <vector>
#include <stdexcept>

class DisjointSet {
public:
    DisjointSet(std::size_t s);
    ~DisjointSet()noexcept;
    int findSetRoot(int x);
    void unify(int x, int y);

private:
    std::vector<int> parent;
    std::vector<int> size;
};

#endif  //DIS_SET_HPP_