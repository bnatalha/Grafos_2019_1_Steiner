#include "Header.hpp"   // Cabeçalho principal
#include "SteinerGraph.hpp"   // Cabeçalho do grafo
// #include "Edge.hpp"     // Arestas utilizadas no grafo de steiner
#include <thread>   // PARA TESTE

using std::cin;
using std::cout;
using std::endl;

std::string duration();

/**
 * Classe principal para a inicialização e execução do programa
 */
int main(int argc, char const *argv[])
{


    // Instanciando grafo de steiner
    SteinerGraph ini_graph = SteinerGraph();
    
    ini_graph.readFromCin();    // Leitura 
    ini_graph.addSteinerRoot(); // Transforma numa árvore de steiner acrescentando uma raiz

    ini_graph.printSteinerSet();
    ini_graph.printTerminalSet();
    std::cout << std::endl;

    ini_graph.printEdges();
    std::cout << std::endl;

    SteinerGraph minTree = ini_graph.calcSteinerMWT();

    std::cout << "Custo: " << minTree.getTotalWeight() << std::endl;

    minTree.writeToFile("output.txt");   // escrevendo grafo em arquivo

    return 0;
}

std::string duration()
{
    auto t0 = std::chrono::steady_clock::now();
    /**
     * Insira código aqui
     */

    std::chrono::seconds dura(3);      // PARA TESTE.
    std::this_thread::sleep_for(dura); // PARA TESTE

    auto t1 = std::chrono::steady_clock::now();
    auto t = t1 - t0;
    auto tmin = std::chrono::duration_cast<std::chrono::minutes>(t);
    auto tsec = std::chrono::duration_cast<std::chrono::seconds>(t);

    std::string min = std::to_string(tmin.count()) + " minutes and ";
    std::string sec = std::to_string(tsec.count()) + " seconds and ";

    return min + sec;
}
