#include "Header.hpp"
#include "Edge.hpp"

#ifndef SRC_STEINERGRAPH_HPP_
#define SRC_STEINERGRAPH_HPP_

class SteinerGraph
{
    private:
        std::unordered_set<int> steiner, terminal, root; // conjuntos de vértices
        int steinerCount, terminalCount;    // quantidade de vértices em cada conjunto, menos o raiz
        int totalVertices;  // quantidade total de vértices + raiz
        int rootVertex; // índice do vértice raiz; será sempre o maior de todos
        
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

};

#endif // SRC_STEINERGRAPH_HPP_