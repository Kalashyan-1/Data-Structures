#ifndef ADJ_MATRIX_GRAPH
#define ADJ_MATRIX_GRAPH

#include <iostream>
#include <list>
#include <type_traits>
#include <vector>
#include <queue>
#include <stack>
#include <exception>


template <typename T>
concept u_integral = std::is_integral_v<T> && !std::is_signed_v<T>;

template <typename T>
requires u_integral<T>
class GraphMatrix {
public:
    GraphMatrix(std::size_t);
    ~GraphMatrix() noexcept;

    void addEdge(T s, T d);
    void addVertex();
    std::vector<std::size_t> shortesPathUndirected(std::size_t s, std::size_t d);
    constexpr std::size_t size() noexcept;
    void transpose();
    void BFS(T);
    void BFSExtraCase();
    void DFS(T);
    void DFSExtraCase();
    void printMat();

private:
    std::size_t V;
    std::vector<std::vector<bool>> adjMatrix;
};

#include "graphMatrix.cpp"

#endif  //ADJ_MATRIX_GRAPH