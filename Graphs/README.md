# Graph Algorithms

This directory contains C++ implementations of different graph algorithms and representations. Graphs are fundamental data structures used for modeling various real-world problems.

## Table of Contents

- [Adjacency List](#adjacency-list)
- [Adjacency Matrix](#adjacency-matrix)
- [Weighted Adjacency List](#weighted-adjacency-list)
- [Disjoint Set](#disjoint-set)
- [Contributing](#contributing)

## Adjacency List

The Adjacency List representation is a flexible way to represent a graph using a linked list for each vertex. It is suitable for sparse graphs.


### API

- `GraphList()`: The constructor creates an empty graph.
- `~GraphList()`: The destructor cleans up the memory used by the graph.
- `void addEdge(T s, T d)`: Adds an edge between vertices `s` and `d`.
- `void addVertex()`: Adds a new vertex to the graph.
- `std::vector<std::size_t> shortestPathUndirected(std::size_t s, std::size_t d)`: Finds the shortest path between two vertices.
- `constexpr std::size_t size() noexcept`: Returns the number of vertices in the graph.
- `void transpose()`: Transposes the graph.
- `void BFS(T)`: Performs a Breadth-First Search traversal.
- `void BFSExtraCase()`: Example case for BFS.
- `bool isCycledUndirected()`: Checks if the undirected graph contains a cycle.
- `bool isCycledDirected()`: Checks if the directed graph contains a cycle.
- `std::vector<std::size_t> topSort()`: Computes the topological sort of the graph.
- `std::vector<std::vector<std::size_t>> SCC_Kosaraju()`: Computes Strongly Connected Components using Kosaraju's algorithm.
- `std::vector<std::vector<std::size_t>> SCC_Tarjan()`: Computes Strongly Connected Components using Tarjan's algorithm.
- `void DFS(T)`: Performs a Depth-First Search traversal.
- `void DFSRec(T, std::vector<bool>& vec)`: Recursive DFS.
- `void DFSExtraCase()`: Example case for DFS.

### Complexity

- `GraphList()`: O(1)
- `~GraphList()`: O(V + E), where V is the number of vertices and E is the number of edges.
- `void addEdge(T s, T d)`: O(1)
- `void addVertex()`: O(V)
- `std::vector<std::size_t> shortestPathUndirected(std::size_t s, std::size_t d)`: O(V + E), where V is the number of vertices and E is the number of edges.
- `constexpr std::size_t size() noexcept`: O(1)
- `void transpose()`: O(V + E)
- `void BFS(T)`: O(V + E)
- `void BFSExtraCase()`: O(V + E)
- `bool isCycledUndirected()`: O(V + E)
- `bool isCycledDirected()`: O(V + E)
- `std::vector<std::size_t> topSort()`: O(V + E)
- `std::vector<std::vector<std::size_t>> SCC_Kosaraju()`: O(V + E)
- `std::vector<std::vector<std::size_t>> SCC_Tarjan()`: O(V + E)
- `void DFS(T)`: O(V + E)
- `void DFSRec(T, std::vector<bool>& vec)`: O(V + E)
- `void DFSExtraCase()`: O(V + E)

## Adjacency Matrix

The Adjacency Matrix representation uses a 2D array to represent a graph. It is suitable for dense graphs.


### API

- `GraphMatrix()`: The constructor creates an empty graph.
- `~GraphMatrix()`: The destructor cleans up the memory used by the graph.
- `void addEdge(T s, T d)`: Adds an edge between vertices `s` and `d`.
- `void addVertex()`: Adds a new vertex to the graph.
- `std::vector<std::size_t> shortestPathUndirected(std::size_t s, std::size_t d)`: Finds the shortest path between two vertices.
- `constexpr std::size_t size() noexcept`: Returns the number of vertices in the graph.
- `void transpose()`: Transposes the graph.
- `void BFS(T)`: Performs a Breadth-First Search traversal.
- `void BFSExtraCase()`: Example case for BFS.
- `void DFS(T)`: Performs a Depth-First Search traversal.
- `void DFSExtraCase()`: Example case for DFS.
- `void printMat()`: Prints the adjacency matrix.

### Complexity

- `GraphMatrix()`: O(1)
- `~GraphMatrix()`: O(1)
- `void addEdge(T s, T d)`: O(1)
- `void addVertex()`: O(V^2), where V is the number of vertices.
- `std::vector<std::size_t> shortestPathUndirected(std::size_t s, std::size_t d)`: O(V^2), where V is the number of vertices.
- `constexpr std::size_t size() noexcept`: O(1)
- `void transpose()`: O(V^2), where V is the number of vertices.
- `void BFS(T)`: O(V^2), where V is the number of vertices.
- `void BFSExtraCase()`: Example case
- `void DFS(T)`: O(V^2), where V is the number of vertices.
- `void DFSExtraCase()`: Example case for DFS.
- `void printMat()`: O(V^2), where V is the number of vertices.

## Weighted Adjacency List

The Weighted Adjacency List representation extends the adjacency list to support weighted edges.


### API

- `WGraphList()`: The constructor creates an empty weighted graph.
- `~WGraphList()`: The destructor cleans up the memory used by the weighted graph.
- `void addEdge(T s, T d, int w)`: Adds a weighted edge between vertices `s` and `d` with weight `w`.
- `void addVertex()`: Adds a new vertex to the graph.
- `constexpr std::size_t size() noexcept`: Returns the number of vertices in the graph.
- `std::vector<std::size_t> topSort()`: Computes the topological sort of the graph.
- `std::vector<int> SSSP_DAG(T s)`: Computes Single Source Shortest Path (SSSP) using Directed Acyclic Graph (DAG) topology.
- `std::vector<int> SSSP_Dijkstra(T s)`: Computes SSSP using Dijkstra's algorithm.
- `std::vector<int> SSSP_Bellman_Ford(T s)`: Computes SSSP using Bellman-Ford algorithm.
- `int MST_Prim(T s)`: Computes the Minimum Spanning Tree (MST) using Prim's algorithm.
- `int MST_Kruskal(T s)`: Computes the MST using Kruskal's algorithm.

### Complexity

- `WGraphList()`: O(1)
- `~WGraphList()`: O(V + E), where V is the number of vertices and E is the number of edges.
- `void addEdge(T s, T d, int w)`: O(1)
- `void addVertex()`: O(1)
- `constexpr std::size_t size() noexcept`: O(1)
- `std::vector<std::size_t> topSort()`: O(V + E)
- `std::vector<int> SSSP_DAG(T s)`: O(V + E)
- `std::vector<int> SSSP_Dijkstra(T s)`: O(V + E) with an adjacency list or O((V + E )log V) with an adjacency matrix.
- `std::vector<int> SSSP_Bellman_Ford(T s)`: O(V * E) in the worst case.
- `int MST_Prim(T s)`: O(V + E) with an adjacency list or O((V + E )log V) with an adjacency matrix.
- `int MST_Kruskal(T s)`: O(E log E), where E is the number of edges.

## Disjoint Set

The Disjoint Set is used in various graph algorithms, such as Kruskal's algorithm for finding Minimum Spanning Trees (MST).

- **disjointSet.hpp**: Contains the `DisjointSet` class implementation.

### API

- `DisjointSet()`: The constructor creates an empty disjoint set with size `s`.
- `~DisjointSet() noexcept`: The destructor cleans up the memory used by the disjoint set.
- `int findSetRoot(int x)`: Finds the root of the set containing element `x`.
- `void unify(int x, int y)`: Unifies the sets containing elements `x` and `y`.

### Complexity

- `DisjointSet()`: O(n), where n is the size of the set.
- `~DisjointSet() noexcept`: O(1)
- `int findSetRoot(int x)`: O(log n) on average, where n is the size of the set.
- `void unify(int x, int y)`: O(log n) on average, where n is the size of the set.



## Contributing

Contributions are welcome! If you'd like to improve these graph algorithms or have suggestions, feel free to open an issue or create a pull request.


