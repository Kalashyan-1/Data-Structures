#ifndef ADJ_LIST_GRAPH_
#define ADJ_LIST_GRAPH_

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
class GraphList {
public:
    GraphList(std::size_t v);
    ~GraphList() noexcept;

    GraphList(const GraphList&);
    GraphList& operator=(const GraphList&);

    GraphList(GraphList&&);
    GraphList& operator=(GraphList&&);

    void addEdge(T s, T d);
    void addVertex();
    std::vector<std::size_t> shortesPathUndirected(std::size_t s, std::size_t d);
    constexpr std::size_t size() noexcept;
    void transpose();
    void BFS(T);
    void BFSExtraCase();
    bool isCycledUndirected();
    bool isCycledDirected();
    std::vector<std::size_t> topSort();
    std::vector<std::vector<std::size_t>> SCC_Kosaraju();
    std::vector<std::vector<std::size_t>> SCC_Tarjan();
    void DFS(T);
    void DFSRec(T, std::vector<bool>& vec);
    void DFSExtraCase();

private:
    bool dfsCylcedUndir(std::vector<bool>& visited, std::size_t source, std::size_t parent);
    bool dfsCylcedDir(std::vector<bool>& visited, std::vector<bool>& recStack, std::size_t source);
    void dfs_Kosaraju(std::vector<bool>& visited, std::size_t source, std::stack<std::size_t>& st);
    void dfs_Kosaraju(std::vector<bool>& visited, std::size_t source, std::vector<std::size_t>& vec);
    void dfs_Tarjan(int u, std::vector<int>& low, std::vector<int>& ids, std::vector<bool>& recStack, std::stack<std::size_t>& st, std::vector<std::vector<std::size_t>>& res);

private:
    std::size_t V;
    std::list<T>* adjList;
};

#include "graphList.tpp"

#endif  //ADJ_LIST_GRAPH_