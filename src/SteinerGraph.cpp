#include "SteinerGraph.hpp"

SteinerGraph::SteinerGraph() {}

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

    // calcula índice do vértice raiz
    // rootVertex = steinerCount + terminalCount;
    rootVertex = 0;
    
    // calcula total de vértices
    totalVertices = steinerCount + terminalCount + 1;   // +1 da raiz

    // prepara a matriz de adjacencia para receber os dados
    matrix = std::vector<std::vector<int>>(totalVertices);
    for (int i = 0; i < totalVertices; i++)
    {
        matrix[i].resize(totalVertices, 0);
        matrix[i][i] = 0;
    }

    // enche a matriz de adjacencia com os dados lidos da entrada padrão
    for (int i = 0; i < edgesCount; i++)
    {
        int o, d, c;    // origin, destination, cost
        std::cin >> o >> d >> c;    // leitura

        // adicionando na matriz de adjacencia
        matrix[o][d] = matrix[d][o] = c;
        matrix[0][o] = matrix[o][0] = 0;

        // adicionando nos conjuntos de vértices
        steiner.insert(o);
        terminal.insert(d);

        // adicionando no vector edges
        Edge newEdge(o, d, c); // [REVIEW] deveria criar e inserir tb a aresta na direção oposta?
        edges.push_back(newEdge);
    }

    printMatrix(); // PARA TESTE
    std::cout << std::endl;

    // adiciona arestas auxiliares que ligam o vértice raiz aos vértices de steiner
    for (int v: steiner)
    {
        // adicionando na matriz de adjacencia
        matrix[v][rootVertex] = matrix[rootVertex][v] = 1;  // arestas (raiz,steiner) tem peso 1 por convenção.

        // adicionando no vector edges
        Edge newEdge(rootVertex, v, 1);  // [REVIEW] deveria criar e inserir tb a aresta na direção oposta?
        edges.push_back(newEdge);
    }

    printMatrix(); // PARA TESTE
    std::cout << std::endl;
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
 * Imprimi matriz de adjacência.
 */
void SteinerGraph::printMatrix(){
    // header
    std::cout << "Adj ";
    for (int i = 0; i < totalVertices; i++) std::cout << i << " ";
    std::cout << std::endl;
    for (int i = 0; i < totalVertices; i++) std::cout << "---";
    std::cout << std::endl;
    
    // body
    for (int i = 0; i < totalVertices; i++)
    {
        std::cout << i << "|  ";
        for (int j = 0; j < totalVertices; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
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