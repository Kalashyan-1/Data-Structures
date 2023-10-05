#include "wgraphList.hpp"

int main() {
    WGraphList<std::size_t> gr(8);
    // Cyclic
    gr.addEdge(0, 1, 1);
    gr.addEdge(0, 2, 2);
    gr.addEdge(1, 2, 3);
    gr.addEdge(1, 3, 4);
    gr.addEdge(2, 5, 5);
    gr.addEdge(3, 0, 6);
    gr.addEdge(4, 5, 7);

    //Acyclic
    // gr.addEdge(0, 1, 1);
    // gr.addEdge(0, 2, 2);
    // gr.addEdge(1, 3, 4);
    // gr.addEdge(2, 5, 5);
    // gr.addEdge(4, 5, 7);

    // std::cout << gr.MST_Prim(5) << std::endl;
    std::cout << gr.MST_Kruskal(0);
    // auto vec = gr.SSSP_DAG(0);
    // auto vec = gr.topSort();

    // gr.addEdge(0, 1, 2);
    // gr.addEdge(0, 2, 3);
    // gr.addEdge(1, 3, 4);
    // gr.addEdge(1, 2, 1);
    // gr.addEdge(2, 3, 1);
    // gr.addEdge(2, 4, 5);
    // gr.addEdge(3, 4, 1);
    // gr.addEdge(3, 5, 3);
    // gr.addEdge(4, 5, 2);

    // gr.addEdge(0, 4, 3);
    // gr.addEdge(1, 0, 9);
    // gr.addEdge(2, 5, 2);
    // gr.addEdge(3, 7, 8);
    // gr.addEdge(4, 6, 4);
    // gr.addEdge(5, 3, 8);
    // gr.addEdge(6, 5, 3);
    // gr.addEdge(3, 7, 8);
    
    // auto vec = gr.SSSP_Dijkstra(0);

    
    // gr.addEdge(0, 1, 4);
    // gr.addEdge(0, 2, 2);
    // gr.addEdge(1, 2, 3);
    // gr.addEdge(1, 3, 2);
    // gr.addEdge(1, 4, 3);
    // gr.addEdge(2, 1, 1);
    // gr.addEdge(2, 3, 3);
    // gr.addEdge(2, 4, 5);
    // gr.addEdge(4, 3, -5);



    // auto vec = gr.SSSP_Bellman_Ford(0);
    // for (auto u : vec) {
    //     // for (auto v : u) {
    //         std::cout << u << " ";
    //     // }
    //     // std::cout << std::endl;
    // }
}