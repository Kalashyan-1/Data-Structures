#include "wgraphList.hpp"
template <typename T>
WGraphList<T>::WGraphList(std::size_t v) 
    : V{v}, adjList(V)
{    
}
template <typename T>
WGraphList<T>::~WGraphList() noexcept {}

template <typename T>
WGraphList<T>::WGraphList(const WGraphList& oth) {
    V = oth.V;
    adjList = oth.adjList;
}

template <typename T>
WGraphList<T>& WGraphList<T>::operator=(const WGraphList& rhs) {
    if (this == &rhs) {return *this;}
    V = rhs.V;
    adjList = rhs.adjList;
    return *this;
}

template <typename T>
WGraphList<T>::WGraphList(WGraphList&& rhs) {
    V = rhs.V;
    adjList = std::move(rhs.adjList);
}
template <typename T>
WGraphList<T>& WGraphList<T>::operator=(WGraphList&& rhs) {
    V = rhs.V;
    adjList = std::move(rhs.adjList);
    return *this;
}

template <typename T>
void WGraphList<T>::addEdge(T s, T d, int w) {
    if (s >= V || d >= V) {throw std::invalid_argument("Given sours or destination is grather then vertex degree.");}
    adjList[s].push_back({d, w});
    // adjList[d].push_back({s, w});  // for undirected weighted graph
}

template <typename T>
void WGraphList<T>::addVertex() {
    adjList.push_back({});
    ++V;
}

template <typename T>
constexpr std::size_t WGraphList<T>::size() noexcept {
    return V;
}

template <typename T>
std::vector<std::size_t> WGraphList<T>::topSort() {
    std::vector<int> indegree(V, 0);
    std::queue<std::size_t> qu;
    std::vector<std::size_t> res(V);
    for (int i = 0; i < V; ++i) {
        for (auto v : adjList[i]) {
            ++indegree[v.first];
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
            if (--indegree[v.first] == 0) {
                qu.push(v.first);
            }
        }
    }
    if (index != V) {return {};}
    return res;
}


//Single source shortest path (SSSP)
//The following algorithm will work only for DAGs
template <typename T>
std::vector<int> WGraphList<T>::SSSP_DAG(T s) {
    const int INFINITY = std::numeric_limits<int>::max();
    if (s > V) {throw std::invalid_argument("Given sours is grather then vertex degree.");}
    std::vector<int> dist(V,  INFINITY);
    auto topSorted = topSort();
    dist[s] = 0;

    for (auto i : topSorted) {
        if (dist[i] != INFINITY) {
            for (auto v : adjList[i]) {
                if (dist[v.first] > dist[i] + v.second) {
                    dist[v.first] = dist[i] + v.second;
                }
            }
        }
    }
    return dist;
}


// Dijkstra's alogrith to find the shortest path between a starting vertex and all other vertices in a graph
template <typename T>
std::vector<int> WGraphList<T>::SSSP_Dijkstra(T s) {
    const int INFINITY = std::numeric_limits<int>::max();
    std::vector<int> dist(V, INFINITY);
    std::priority_queue<std::pair<T, int>> pq; 
    std::vector<bool> visited(V, false);
    dist[s] = 0;
    pq.push({s, 0});

    while (!pq.empty()) {
        auto u = pq.top().first;
        auto w = pq.top().second;
        pq.pop();

        if (dist[u] < w) continue;

        visited[u] = true;

        for (auto v : adjList[u]) {
            if (!visited[v.first]) {
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push({v.first, dist[v.first]});
                }
            }
        }
    }
    return dist;    
}

//Bellman-Ford's used to find the shortest path between a starting vertex and all other vertices in a graph. 
//It can handle graphs with negative edge weights, unlike Dijkstra's algorithm.
template <typename T>
std::vector<int> WGraphList<T>::SSSP_Bellman_Ford(T s) {
    const int INFINITY = std::numeric_limits<int>::max();
    std::vector<int> dist(V, INFINITY);
    dist[s] = 0;
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (auto v : adjList[u]) {
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                } 
            }
        }
    }

    for (int u = 0; u < V; ++u) {
        for (auto v : adjList[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                std::cout << "Negative cycle is detected\n";
                return {};
            } 
        }
    }
    return dist;
}


template <typename T>
int WGraphList<T>::MST_Prim(T s) {
    if (s >= V) {throw std::invalid_argument("Given sours is grather then vertex degree.");}
    int cost = 0;
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> qu;
    std::vector<bool> visited(V, false);
    qu.push({0, s});
    while (!qu.empty()) {
        auto u = qu.top().second;
        auto w = qu.top().first;
        qu.pop();
        if (visited[u]) continue;
        visited[u] = true;
        std::cout << w << " ";

        cost += w;
        for (auto v : adjList[u]) {
            if (!visited[v.first]) {
                qu.push({v.second, v.first});
            }
        }
    }
    return cost;
}



template <typename T>
std::vector<std::vector<int>> WGraphList<T>::adjList2Edge() {
    std::vector<std::vector<int>> res;

    for (int i = 0; i < V; ++i) {
        for (auto v : adjList[i]) {
            std::vector<int> tmp;
            tmp.push_back(i);
            tmp.push_back(v.first);
            tmp.push_back(v.second);
            res.push_back(tmp);
        }
    }

    std::sort(res.begin(), res.end(), [](const std::vector<int>& x, const std::vector<int>& y) {
        return x[2] < y[2];
    });

    return res;
}


template <typename T>
int WGraphList<T>::MST_Kruskal(T s) {
    if (s >= V) {throw std::invalid_argument("Given sours is grather then vertex degree.");}
    int cost = 0;
    auto edges = adjList2Edge();
    
    DisjointSet set(V);
    
    for (auto e : edges) {
        std::cout << e[0] << e[1] << e[2] << "\n";
        if(set.findSetRoot(e[0]) != set.findSetRoot(e[1])) {
            cost += e[2];
            std::cout << e[2] << "\n";
            set.unify(e[0], e[1]);
        }
    }
    return cost;
}

