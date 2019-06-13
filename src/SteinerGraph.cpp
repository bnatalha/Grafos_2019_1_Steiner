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

    // prepara a lista/vector de adjacencia para receber os dados
    edges.resize(totalVertices);
    edges.shrink_to_fit();

    // enche a lista/vector de adjacencia com os dados lidos da entrada padrão
    for (int i = 0; i < edgesCount; i++)
    {
        int m, d, c;    // medicamento, doença, custo        
        std::cin >> m >> d >> c;    // leitura
        
        steiner.insert(m);  // adicionando nos conjuntos de vértices
        terminal.insert(d);

        edges[d].push_back(Edge(d,m,c)); // add aresta
    }
}

void SteinerGraph::addSteinerRoot()
{
    root.insert(ROOT_VERTEX);    // adiciona o vértice raiz no seu conjunto

    for (int m: steiner)
    {        
        edges[m].push_back(Edge(m, ROOT_VERTEX, ROOT_WEIGHT)); // adicionando no vector edges (medicamento, raiz)
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
 * Imprime as arestas no saída padrão.
 */
void SteinerGraph::printEdges(){
    for (int i = 0; i < edges.size(); i++)
    {
        std::cout << i << "-> ";
        for (Edge e : edges[i])
        {
            std::cout << std::setfill(' ') << std::setw(2) << e << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Cria um arquivo com a o grafo em formato de lista de adjacencia.
 * @param filename nome do arquivo
 */
void SteinerGraph::writeToFile(std::string filename)
{
    std::string pathtofile = "out/" + filename;
    std::ofstream example(pathtofile);
    if (example.is_open())
    {
        // Steiner set
        example << "Medicamentos: " ;
        for (int m : steiner)
        {
            example << m << " ";
        }
        example << std::endl;

        // Custo
        example << "Custo Total: " << getTotalWeight() << std::endl;

        // arestas
        for (std::vector<Edge> vec : edges)
        {
            if (!vec.empty())
            {
                for (Edge e : vec)
                {
                    example << std::setfill(' ') << std::setw(2) << e << " ";
                }
                example << std::endl;
            }
        }
        example.close();
    }
}

/**
 * Dado um vértice v, retorna a aresta de menor custo incidente dele;
 */
Edge SteinerGraph::getMinWeightEdge(int v)
{
    std::vector<Edge> myEdges = edges[v];
    Edge minWeightEdge = Edge(0,0,INT32_MAX);
    for(Edge e : myEdges)
    {
        if(e < minWeightEdge)
        {
            minWeightEdge = e;
        }
    }

    return minWeightEdge;
}

int SteinerGraph::getTotalWeight()
{
    int sum = 0;
    for (std::vector<Edge> vec : edges)
    {
        for (Edge e: vec)
        {
            sum += e.getCost();
        }
    }
    
    return sum;
}

/**
 * Retorna a árvore de Steiner de custo mínimo
 */
SteinerGraph SteinerGraph::calcSteinerMWT()
{
    SteinerGraph T; // Incializo árvore T
    T.edges.resize(edges.size());

    for(int d: terminal)
    {
        Edge minCostEdge = getMinWeightEdge(d); // pega a menor aresta que sái de 'd'
        T.terminal.insert(d);   // add doença
        T.edges[d].push_back(minCostEdge);  // add custo
        T.steiner.insert(minCostEdge.getDestination()); // add medicamento       
    }

    
    T.edges.shrink_to_fit();    // compactando
    T.printSteinerSet();
    std::cout << "Custo mínimo: " << T.getTotalWeight() << std::endl;
    T.printEdges();

    return T;
}