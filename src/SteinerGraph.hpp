#include "Header.hpp"
#include "Edge.hpp"

#ifndef SRC_STEINERGRAPH_HPP_
#define SRC_STEINERGRAPH_HPP_

const int ROOT_VERTEX = 0;
const int ROOT_WEIGHT = 1;

class SteinerGraph
{
    public:
        std::unordered_set<int> steiner, terminal, root; // conjuntos de vértices
        int totalVertices;  // quantidade total de vértices + raiz
        
        std::vector<Edge> edges; // arestas
        int edgesCount; // quantidade de arestas

        std::vector<std::vector<int>> matrix;   // matriz de adjacência

    private:
        void printVertexSet(std::unordered_set<int>, std::string);

    public:
        SteinerGraph(/* args */);
        ~SteinerGraph();

        void readFromCin();
        void printSteinerSet();
        void printTerminalSet();
        void printEdges();
        void printMatrix();

        void writeToFile(std::string);

        void addSteinerRoot();
        void calcSteinerMWT();
};

#endif // SRC_STEINERGRAPH_HPP_