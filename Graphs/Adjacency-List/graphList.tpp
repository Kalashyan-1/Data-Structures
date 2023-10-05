#include "graphList.h"

template <typename T>
GraphList<T>::GraphList(std::size_t v) : V{v} {
    adjList = new std::list<T>[v];
}

template <typename T>
GraphList<T>::~GraphList() noexcept {
    delete[] adjList;
}

template <typename T>
GraphList<T>::GraphList(const GraphList& oth) {
    this->V = oth.V;
    this->V = oth.adjList;
}

template <typename T>
GraphList<T>& GraphList<T>::operator=(const GraphList& rhs) {
    if (this == &rhs) {return *this;}
    this->V = rhs.V;
    this->adjList = rhs.adjList;
    return *this;    
}

template <typename T>
GraphList<T>::GraphList(GraphList&& oth) {
    this->V = std::move(oth.V);
    this->adjList= std::move(oth.adjList);
    oth.adjList = nullptr;
}

template <typename T>
GraphList<T>& GraphList<T>::operator=(GraphList&& rhs) {
    if (this == &rhs) {return *this;}
    this->V = std::move(rhs.V);
    this->adjList= std::move(rhs.adjList);
    rhs.adjList = nullptr;
    return *this;
}

template <typename T>
void GraphList<T>::addEdge(T s, T d) {
    if (s > V || d > V) {throw std::invalid_argument("Given sours or destination is grather then vertex count.");}
    adjList[s].push_back(d);
    // adjList[d].push_back(s); // for undirected graphLists
}

template <typename T>
void GraphList<T>::addVertex() {
    std::list<T>* tmp = new std::list<T>[V + 1];
    for (std::size_t i = 0; i < V; ++i) {
        tmp[i] = adjList[i];
    }
    delete[] adjList;
    adjList = tmp;
    tmp = nullptr;
    ++V;
}

template <typename T>
constexpr std::size_t GraphList<T>::size() noexcept {
    return V;
}


//Transpose function is only for directed graphLists
template <typename T>
void GraphList<T>::transpose() {
    std::list<T>* tmp = new std::list<T>[V];
    for (std::size_t i = 0; i < V; ++i) {
        auto it = adjList[i].begin();
        for (; it != adjList[i].end(); ++it) {
            tmp[*it].push_back(i);
        }
    }
    delete[] adjList;
    adjList = tmp;
    tmp = nullptr;
}

template <typename T>
std::vector<std::size_t> GraphList<T>::shortesPathUndirected(std::size_t s, std::size_t d) {
    if (s == d) {return {};}
    if (s > V || d > V) {throw std::invalid_argument("Given sours or destination is grather then vertex count.");}

    std::vector<bool> visited(V, false);
    std::vector<int> parent(V, -1);
    std::queue<std::size_t> qu;
    qu.push(s);
    visited[s] = true;
    while (!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        if (u == d) break;
        for (auto a : adjList[u]) {
            if (!visited[a]) {
                qu.push(a);
                parent[a] = u;
                visited[a] = true;
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
 
// This function allows traverse over all vertices using BFS treaversal even if we have a set of disconnected Graph
template <typename T>
void GraphList<T>::BFSExtraCase() {
    std::vector<bool> visited(V, false);
    for (std::size_t i = 0; i < V; ++i) {
        if (!visited[i]) {

            std::queue<std::size_t> qu;
            visited[i] = true;
            qu.push(i);

            while (!qu.empty()) {
                auto u = qu.front();
                qu.pop();
                std::cout << u << " "; 
                for (auto a : adjList[u]) {
                    if (!visited[a]) {
                        visited[a] = true;
                        qu.push(a);
                    }
                } 
            }
        }
    }
}

template <typename T>
void GraphList<T>::BFS(T s) {
    if (s > V) {return;}
    std::vector<bool> visited(V, false);
    visited[s] = true;
    std::queue<std::size_t> qu;
    qu.push(s);
    while (!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        std::cout << u << " ";
        for (auto a : adjList[u]) {
            if (!visited[a]) {
                qu.push(a);
                visited[a] = true;
            }
        }
    }
}

template <typename T>
void GraphList<T>::DFSExtraCase() {
    std::vector<bool> visited(V, false);
    for (std::size_t i = 0; i < V; ++i) {
        if (!visited[i]) {
            std::stack<std::size_t> st;
            visited[i] = true;
            st.push(i);
            while (!st.empty()) {
                auto u = st.top();
                st.pop();
                std::cout << u << " ";
                for (auto a : adjList[u]) {
                    if (!visited[a]) {
                        visited[a] = true;
                        st.push(a);
                    }
                }
            }
        }
    }
}

template <typename T>
void GraphList<T>::DFSRec(T s, std::vector<bool>& visited) {
    visited[s] = true;
    std::cout << s << " ";
    for (auto a : adjList[s]) {
        if (!visited[a]) {
            DFSRec(a, visited);
        }
    }
}

template <typename T>
void GraphList<T>::DFS(T s) {
    if (s > V) {return;}
    std::vector<bool> visited(V, false);
    visited[s] = true;
    std::stack<std::size_t> st;
    st.push(s);
    while (!st.empty()) {
        auto u = st.top();
        st.pop();
        std::cout << u << " ";
        for (auto a : adjList[u]) {
            if (!visited[a]) {
                st.push(a);
                visited[a] = true;
            }
        }
    }
}
template <typename T>
bool GraphList<T>::dfsCylcedUndir(std::vector<bool>& visited, std::size_t source, std::size_t parent) {
    visited[source] = true;
    for (auto v : adjList[source]) {
        if (!visited[v]) {
            if (dfsCylcedUndir(visited, v, source)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool GraphList<T>::isCycledUndirected() {
    std::vector<bool> visited(V, false);
    for (std::size_t u = 0; u < adjList->size(); ++u) {
        if (!visited[u]) {
            if (dfsCylcedUndir(visited, u, -1)){
                return true;
            }
        }
    }
    return false;
}

template <typename T>
bool GraphList<T>::isCycledDirected() {
    std::vector<bool> visited(V, false);
    std::vector<bool> recStack(V, false);
    for (std::size_t i = 0; i < adjList->size(); ++i) {
        if (!visited[i]) {
            if (dfsCylcedDir(visited, recStack, i)) {
                return true;
            }
        }
    }
    return false;
}


template <typename T>
bool GraphList<T>::dfsCylcedDir(std::vector<bool>& visited, std::vector<bool>& recStack, std::size_t source) {
    visited[source] = true;
    recStack[source] = true;

    for (auto v : adjList[source]) {
        if (!visited[v]) {
            if (dfsCylcedDir(visited, recStack, v)) {
                return true;
            }
        } else if (recStack[source]) {
            return true;
        }
    }
    recStack[source] = false;
    return false;
}

// Topological Sorting
//kahn's algorithm
template <typename T>
std::vector<std::size_t> GraphList<T>::topSort() {
    std::vector<int> indegree(V, 0);
    std::vector<std::size_t> res(V);
    std::queue<std::size_t> qu;
    for (int u = 0; u < V; ++u) {
        for (auto v : adjList[u]) {
            indegree[v]++;
        }
    }

    for (std::size_t i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            qu.push(i);
        }
    }
    int index = 0;
    while (!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        res[index++] = u;
        for (auto v : adjList[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                qu.push(v);
            }
        }
    }

    std::cerr << index << std::endl;
    if (index != V) {
        throw std::logic_error("Graph contains a cycle");
    }
    return res;
}

// Strongly connected components 
// Kosaraju's algorithm
template <typename T>
std::vector<std::vector<std::size_t>> GraphList<T>::SCC_Kosaraju() {
    std::vector<bool> visited(V, false);
    std::stack<std::size_t> st;
    std::vector<std::vector<std::size_t>> res;
    for (std::size_t i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs_Kosaraju(visited, i, st);
        }
    }

    auto tmpgraph = adjList;
    transpose();

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    while (!st.empty()) {
        auto u = st.top();
        st.pop();
        if (!visited[u]) {
            std::vector<std::size_t> tmp;
            dfs_Kosaraju(visited, u, tmp);
            res.push_back(tmp);
        }
    }
    transpose();
    return res;
}


// Used in SCC
template <typename T>
void GraphList<T>::dfs_Kosaraju(std::vector<bool>& visited, std::size_t source, std::stack<std::size_t>& st) {
    visited[source] = true;
    for (auto v : adjList[source]) {
        if (!visited[v]) {
            // visited[v] = true;
            dfs_Kosaraju(visited, v, st);
        }
    }
    st.push(source);
}


// Used in SCC
template <typename T>
void GraphList<T>::dfs_Kosaraju(std::vector<bool>& visited, std::size_t source, std::vector<std::size_t>& vec) {
    visited[source] = true;
    vec.push_back(source);
    for (auto v : adjList[source]) {
        if (!visited[v]) {
            dfs_Kosaraju(visited, v, vec);
        }
    }
}


// Strongly Connected component
// Tarjan's algorithm 
template <typename T>
std::vector<std::vector<std::size_t>> GraphList<T>::SCC_Tarjan() {
    std::vector<int> low(V, 0);
    std::vector<int> ids(V, -1);
    std::vector<bool> recStack(V, false);
    std::stack<std::size_t> st;
    std::vector<std::vector<std::size_t>> res;

    for (int i = 0; i < V; ++i) {
        if(ids[i] == -1) {
            dfs_Tarjan(i, low, ids, recStack, st, res);
        }
    }
    return res;
}

template <typename T>
void GraphList<T>::dfs_Tarjan(int u, std::vector<int>& low, std::vector<int>& ids, std::vector<bool>& recStack, std::stack<std::size_t>& st, std::vector<std::vector<std::size_t>>& res) {
    static int id = 0;
    recStack[u] = true;
    st.push(u);
    low[u] = ids[u] = id++;
    for (auto v : adjList[u]) {
        if (ids[v] == -1) {
            dfs_Tarjan(v, low, ids, recStack, st, res);
        }
        if (recStack[v]) {
            low[u] = std::min(low[u], low[v]);
        }
    }
    if (low[u] == ids[u]) {
        std::vector<std::size_t> tmp;
        for (auto i = st.top(); ; i = st.top()) {
            st.pop();            std::vector<std::size_t> tmp;

            tmp.push_back(i);
            recStack[i] = false;
            if (i == u) break;
        }
        res.push_back(tmp);
    }
}

