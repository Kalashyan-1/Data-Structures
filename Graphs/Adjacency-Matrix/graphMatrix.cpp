#include "graphMatrix.h"

template <typename T>
GraphMatrix<T>::GraphMatrix(std::size_t v) 
: V{v}, adjMatrix{v, std::vector<bool>(v, false)}
{   
}

template <typename T>
GraphMatrix<T>::~GraphMatrix() noexcept {}

template <typename T>
void GraphMatrix<T>::addEdge(T s, T d) {
    adjMatrix[s][d] = true;
    adjMatrix[d][s] = true;  // for undirected graphs
}

template <typename T>
void GraphMatrix<T>::addVertex() {
    for (int i = 0; i < V; ++i) {
        adjMatrix[i].push_back(false);
    }
    adjMatrix.push_back(std::vector<bool>(V + 1, false));
    ++V;
}

template <typename T>
std::vector<std::size_t> GraphMatrix<T>::shortesPathUndirected(std::size_t s, std::size_t d) {
    if (s == d) {return {};}
    if (s > V || d >V) {throw std::invalid_argument("Given sours or destination is grather then vertex count.");}
    std::vector<bool> visited(V, false);
    std::vector<int> parent(V, -1);
    std::stack<std::size_t> st;
    visited[s] = true;
    st.push(s);
    while (!st.empty()) {
        auto u = st.top();
        st.pop();
        if (u == d) {break;}
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[u][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = u;
                st.push(i);
            }
        }
    }
    std::vector<std::size_t> shortestPath;
    std::size_t curr = d;
    while (curr != -1) {
        shortestPath.push_back(curr);
        curr = parent[curr];
    }
    std::reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

template <typename T>
constexpr std::size_t GraphMatrix<T>::size() noexcept {
    return V;
}

template <typename T>
void GraphMatrix<T>::transpose() {
    for (int i = 0; i < V/2; ++i) {
        for (int j = i + 1; j < V; ++j) {
            std::swap(adjMatrix[i][j], adjMatrix[j][i]);
        }
    }
}

template <typename T>
void GraphMatrix<T>::BFS(T s) {
    std::vector<bool> visited(V, false);
    std::queue<std::size_t> qu;
    visited[s] = true;
    qu.push(s);
    while (!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        std::cout << u << " ";
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[u][i] && !visited[i]) {
                visited[i] = true;
                qu.push(i);
            }
        }
    }
}

template <typename T>
void GraphMatrix<T>::BFSExtraCase() {
    std::vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            std::queue<std::size_t> qu;
            visited[i] = true;
            qu.push(i);
            while (!qu.empty()) {
                auto u = qu.front();
                qu.pop();
                std::cout << u << " ";
                for (int j = 0; j < V; ++j) {
                    if (adjMatrix[u][j] && !visited[j]) {
                        visited[j] = true;
                        qu.push(j);
                    }
                }
            }
        }
    }
}

template <typename T>
void GraphMatrix<T>::DFS(T s) {
    std::vector<bool> visited(V, false);
    std::stack<std::size_t> st;
    visited[s] = true;
    st.push(s);
    while (!st.empty()) {
        auto u = st.top();
        st.pop();
        std::cout << u << " ";
        for (int i = 0; i < V; ++i) {
            if (adjMatrix[u][i] && !visited[i]) {
                visited[i] = true;
                st.push(i);
            }
        }
    }
}

template <typename T>
void GraphMatrix<T>::DFSExtraCase() {
    std::vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            std::stack<std::size_t> st;
            visited[i] = true;
            st.push(i);
            while (!st.empty()) {
                auto u = st.top();
                st.pop();
                std::cout << u << " ";
                for (int j = 0; j < V; ++j) {
                    if (adjMatrix[u][j] && !visited[j]) {
                        visited[j] = true;
                        st.push(j);
                    }
                }
            }
        }
    }
}

template <typename T>
void GraphMatrix<T>::printMat() {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}