#include "graphMatrix.h"

int main() {
    GraphMatrix<std::size_t> gr(10);
    //undirected graph
    gr.addVertex();
    gr.addEdge(0, 1);
    gr.addEdge(1, 2);
    gr.addEdge(2, 0);
    gr.addEdge(2, 3);
    gr.addEdge(3, 0);
    gr.addEdge(3, 1);
    gr.addEdge(1, 5);
    gr.addEdge(5, 4);
    gr.addEdge(2, 4);
    std::cout << std::endl;
    for (auto a : gr.shortesPathUndirected(0, 4)){
        std::cout << a << " ";
    }
    
    //directed graph
    // GraphMatrix<std::size_t> gr2(5);    
    // gr2.addEdge(0, 1);
    // gr2.addEdge(1, 2);
    // gr2.addEdge(1, 3);
    // gr2.addEdge(4, 0);
    // gr2.addEdge(4, 1);
    // gr2.printMat();
    // std::cout << std::endl;
    // gr2.transpose();
    // gr2.printMat();
    // std::cout << std::endl;
    // gr.addEdge(3, 1);
    // gr.addEdge(1, 5);
    // gr.addEdge(5, 4);
    // gr.addEdge(2, 4);


    // gr2.BFS(0);
    // gr.DFSExtraCase();
}