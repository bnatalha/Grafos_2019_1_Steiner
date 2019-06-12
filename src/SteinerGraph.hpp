#include "Header.hpp"
#include "Edge.hpp"

#ifndef SRC_STEINERGRAPH_HPP_
#define SRC_STEINERGRAPH_HPP_

class SteinerGraph
{
    private:
        std::unordered_set<int> steiner, terminal; // vértices
        int steinerCount, terminalCount;
        int totalVertices;
        
        std::vector<Edge> edges; // arestas
        int edgesCount;

        std::vector<std::vector<int>> matrix;

    private:
        void printVertexSet(std::unordered_set<int>, std::string);

    public:
        SteinerGraph(/* args */);
        ~SteinerGraph();

        void readFromCin();
        void printSteinerSet();
        void printTerminalSet();
        void printEdges();

        void writeToFile(std::string);
};

#endif // SRC_STEINERGRAPH_HPP_