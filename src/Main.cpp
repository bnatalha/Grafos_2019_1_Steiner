#include "Header.hpp"   // Cabeçalho principal
#include "SteinerGraph.hpp"   // Cabeçalho do grafo
// #include "Edge.hpp"     // Arestas utilizadas no grafo de steiner

using std::cin;
using std::cout;
using std::endl;

/**
 * Classe principal para a inicialização e execução do programa
 */
int main(int argc, char const *argv[])
{
    // Instanciando grafo de steiner
    SteinerGraph graph = SteinerGraph();
    
    // Leitura 
    graph.readFromCin();

    // Testando saida
    graph.printSteinerSet();
    cout << endl;
    graph.printTerminalSet();
    cout << endl;
    graph.printEdges();
    cout << endl;

    // escrevendo grafo em arquivo
    graph.writeToFile("nat.txt");

    return 0;
}