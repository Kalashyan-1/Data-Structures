#ifndef WEIGHTED_GRAPH_ADJ_LIST_
#define WEIGHTED_GRAPH_ADJ_LIST_

#include <iostream>
#include <type_traits>
#include <vector>
#include <queue>
#include <stack>
#include <exception>
#include <limits>
#include "./DisjointSet/disjointSet.hpp"

template <typename T>
concept u_integral = std::is_integral_v<T> && !std::is_signed_v<T>;

template <typename T>
requires u_integral<T>
class WGraphList {    
public:
    WGraphList(std::size_t v);
    ~WGraphList() noexcept;

    WGraphList(const WGraphList&);
    WGraphList& operator=(const WGraphList&);

    WGraphList(WGraphList&&);
    WGraphList& operator=(WGraphList&&);

    void addEdge(T s, T d, int w);
    void addVertex();
    constexpr std::size_t size() noexcept;
    std::vector<std::size_t> topSort();
    std::vector<int> SSSP_DAG(T s);
    std::vector<int> SSSP_Dijkstra(T s);
    std::vector<int> SSSP_Bellman_Ford(T s);
    int MST_Prim(T s);
    int MST_Kruskal(T s);

private: 
    std::vector<std::vector<int>> adjList2Edge();
    
private:
    std::size_t V;
    std::vector<std::vector<std::pair<T, int>>> adjList;
};

#include "wgraphList.tpp"

#endif   //WEIGHTED_GRAPH_ADJ_LIST_