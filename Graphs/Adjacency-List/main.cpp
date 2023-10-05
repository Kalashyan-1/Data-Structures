#include "graphList.h"

int main() {
    // GraphList<std::size_t> gr(8);

    //undirected
    // gr.addVertex();
    // gr.addEdge(0, 1);
    // gr.addEdge(1, 2);
    // gr.addEdge(2, 0);
    // gr.addEdge(2, 3);
    // gr.addEdge(3, 0);
    // gr.addEdge(3, 1);
    // gr.addEdge(1, 5);
    // gr.addEdge(5, 4);
    // gr.addEdge(2, 4);


    // gr.addEdge(0, 1);
    // gr.addEdge(1, 2);
    // gr.addEdge(1, 3);
    // gr.addEdge(2, 3);
    // std::cout << gr.isCycledUndirected();


    //directed
    //case 1
    // gr.addEdge(0, 1);
    // gr.addEdge(1, 2);
    // gr.addEdge(2, 3);
    // gr.addEdge(3, 4);
    // gr.addEdge(4, 1);
    // auto vec =  gr.topSort();
    // for (auto a : vec) {
    //     std::cout << a << " ";
    // }

    // case 2
    // gr.addEdge(1, 0);
    // gr.addEdge(0, 3);
    // gr.addEdge(3, 4);
    // gr.addEdge(0, 2);
    // gr.addEdge(2, 1);

    //case 3
    // gr.addEdge(0, 1);
    // gr.addEdge(1, 2);
    // gr.addEdge(2, 3);
    // gr.addEdge(2, 4);
    // gr.addEdge(3, 0);
    // gr.addEdge(4, 5);
    // gr.addEdge(6, 4);
    // gr.addEdge(5, 6);
    // gr.addEdge(6, 7);

    // case 4

    // gr.addEdge(0, 1);
    // gr.addEdge(1, 2);
    // gr.addEdge(2, 0);
    // gr.addEdge(3, 0);
    // gr.addEdge(3, 2);
    // gr.addEdge(3, 4);
    // gr.addEdge(4, 5);
    // gr.addEdge(5, 3);
    // gr.addEdge(5, 0);
    // gr.addEdge(6, 5);
    // gr.addEdge(5, 0);
    // gr.addEdge(7, 4);
    // gr.addEdge(6, 7);
    // gr.addEdge(7, 6);

    GraphList<std::size_t> gr(7);

    gr.addEdge(0,1);
    gr.addEdge(0,2);
    gr.addEdge(1, 2);
    gr.addEdge(1,3);
    gr.addEdge(2, 5);
    gr.addEdge(3, 0);
    gr.addEdge(4, 5);

    auto vec = gr.SCC_Tarjan();
    for (auto u : vec) {
        for (auto v : u) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }


    



    // gr.DFS(0);
    // std::cout << std::endl;
    // for (auto a : gr.shortesPathUndirected(0, 4)){
    //     std::cout << a << " ";
    // }
    // gr.DFS(0);
    // std::cout << std::endl;
    // std::vector<bool> vec(gr.size(), false);
    // gr.DFSRec(0, vec);
    // gr.BFSExtraCase();
}
