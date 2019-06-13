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
        
        std::vector<std::vector<Edge>> edges; // lista/vector de adjacencia
        int edgesCount; // quantidade de arestas
    private:
        void printVertexSet(std::unordered_set<int>, std::string);

    public:
        SteinerGraph(/* args */);
        ~SteinerGraph();

        void readFromCin();
        void printSteinerSet();
        void printTerminalSet();
        void printEdges();

        std::unordered_set<int> getNeighborhood(int);

        void addSteinerRoot();
        Edge getMinWeightEdge(int);
        int getTotalWeight();
        SteinerGraph calcSteinerMWT();


        void writeToFile(std::string);
};

#endif // SRC_STEINERGRAPH_HPP_