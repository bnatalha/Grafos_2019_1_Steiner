#include "SteinerGraph.hpp"

SteinerGraph::SteinerGraph() {}

SteinerGraph::~SteinerGraph() {}

/**
 * Função auxiliar para imprimer std:unordered_set<int>
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
    int steinerCount, terminalCount;    // quantidade de vértices

    // Leitura da quantidade de vértices
    std::cin >> steinerCount;
    std::cin >> terminalCount;
    std::cin >> edgesCount;
    
    // calcula total de vértices
    totalVertices = steinerCount + terminalCount + 1;   // +1 da raiz

    // prepara a matriz/lista de adjacencia para receber os dados
    matrix = std::vector<std::vector<int>>(totalVertices);
    for (int i = 0; i < totalVertices; i++)
    {
        matrix[i].resize(totalVertices, 0);
        edgesByVertex[i].resize(totalVertices);
    }


    // enche a matriz de adjacencia com os dados lidos da entrada padrão
    for (int i = 0; i < edgesCount; i++)
    {
        int m, d, c;    // medicamento, doença, custo
        
        std::cin >> m >> d >> c;    // leitura

        // adicionando nos conjuntos de vértices
        steiner.insert(m);
        terminal.insert(d);

        matrix[m][d] = matrix[d][m] = c; // adicionando na matriz de adjacencia
        edgesByVertex[d].push_back(Edge(d,m,c));    // adicionando na matriz de adjacencia

        // adicionando no vector edges (doença, medicamento)
        Edge newEdge(d, m, c);        
        edges.push_back(newEdge);
    }

    // compactando/ordenando arestas
    for (std::vector<Edge> vec: edgesByVertex)
    {
        vec.shrink_to_fit();    // compactando
        std::sort(vec.begin(), vec.end()); // ordena crescente
    }
}

void SteinerGraph::addSteinerRoot()
{
    root.insert(ROOT_VERTEX);    // adiciona o vértice raiz no seu conjunto

    // adiciona arestas auxiliares que ligam o vértice raiz aos vértices de steiner (medicamentos)
    for (int m: steiner)
    {
        matrix[m][ROOT_VERTEX] = matrix[ROOT_VERTEX][m] = ROOT_WEIGHT; // adicionando na matriz de adjacencia

        Edge newEdge(m, ROOT_VERTEX, ROOT_WEIGHT); // adicionando no vector edges (medicamento, raiz)
        edges.push_back(newEdge);
    }
}

/*
 * Imprime o set de steiner atual.
 */
void SteinerGraph::printSteinerSet(){
    printVertexSet(steiner, "Steiner");
}

/*
 * Imprime o conjunto de vértices de terminais atual no saída padrão.
 */
void SteinerGraph::printTerminalSet(){
    printVertexSet(terminal, "Terminal");
}

/*
 * Imprime matriz de adjacência.
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
 * Imprime as arestas no saída padrão.
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

// std::vector<Edge> SteinerGraph::getNeighborhood(int v)
// {
//     std::vector<Edge>
// }

/**
 * [TODO]
 */
void SteinerGraph::calcSteinerMWT(/* func caminho mais curto */)
{
    SteinerGraph T; // Incializo árvore T
    T.root.insert(ROOT_VERTEX);  // Adiciono o vértice raiz
    // T.edges.push_back(ROOT_VERTEX)  // Adiciono o vértice raiz

    for(int d: terminal)
    {
        // add caminho mais curto ao conjunto de terminais e arestas.
    }
}