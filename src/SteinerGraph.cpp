#include "SteinerGraph.hpp"

SteinerGraph::SteinerGraph()
{
    root.insert(STEINER_ROOT);
}

SteinerGraph::~SteinerGraph() {}

/**
 * Função auxiliar para imprimir std:unordered_set<int>
 */
void SteinerGraph::printVertexSet(std::unordered_set<int> set, std::string setname)
{
    std::cout << setname + ": ";
    for (int vertex : set)
    {
        std::cout << vertex << " ";
    }
}

/**
 * Ler o grafo da entrada padrão
 */
void SteinerGraph::readFromCin()
{
    // Leitura da quantidade de vértices
    std::cin >> steinerCount;
    std::cin >> terminalCount;
    std::cin >> edgesCount;

    // Calculando total de vértices
    totalVertices = steinerCount + terminalCount + 1;   // +1 da raiz

    // prepara a matriz de adjacencia para receber os dados
    matrix = std::vector<std::vector<int>>(totalVertices);
    for (int i = 0; i < totalVertices; i++)
    {
        matrix[i].resize(totalVertices, -1);
        matrix[i][i] = 0;
    }

    // enche a matriz de adjacencia com os dados lidos da entrada padrão
    for (int i = 0; i < edgesCount; i++)
    {
        int o, d, c;    // origin, destination, cost
        std::cin >> o >> d >> c;

        matrix[o][d] = matrix[d][o] = c;
        matrix[0][o] = matrix[o][0] = 0;
        steiner.insert(o);
        terminal.insert(d);

        Edge newEdge(o, d, c);

        edges.push_back(newEdge);
    }
}

/*
 * Imprimi o set de steiner atual.
 */
void SteinerGraph::printSteinerSet(){
    printVertexSet(steiner, "Steiner");
}

/*
 * Imprimi o conjunto de vértices de terminais atual no saída padrão.
 */
void SteinerGraph::printTerminalSet(){
    printVertexSet(terminal, "Terminal");
}

/*
 * Imprimi as arestas no saída padrão.
 */
void SteinerGraph::printEdges(){
    for (Edge e : edges)
    {
        std::cout << e << std::endl;
    }
}

/**
 * Cria um arquivo com a o grafo em formato de matriz de adjacencia.
 * @param filename nome do arquivo
 */
void SteinerGraph::writeToFile(std::string filename)
{
    std::string pathtofile = "out/" + filename;
    std::ofstream example(pathtofile);
    if (example.is_open())
    {
        for (unsigned long i = 0; i < matrix.size(); i++)
        {
            for (unsigned long j = 0; j < matrix[i].size(); j++)
            {
                // std::cout << std::setfill(' ') << std::setw(2) << matrix[i][j] << " ";
                example << std::setfill(' ') << std::setw(2) << matrix[i][j] << " ";
            }
            // std::cout << std::endl;
            example << std::endl;
        }
        example.close();
    }
}