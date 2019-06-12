#include "Header.hpp"   // Cabeçalho principal
#include "SteinerGraph.hpp"   // Cabeçalho do grafo
// #include "Edge.hpp"     // Arestas utilizadas no grafo de steiner
#include <thread>

using std::cin;
using std::cout;
using std::endl;

std::string duration()
{
    auto t0 = std::chrono::steady_clock::now();
    /**
     * Insira código aqui
     */

    std::chrono::seconds dura(3);   // PARA TESTE. 
    std::this_thread::sleep_for(dura);  // PARA TESTE

    auto t1 = std::chrono::steady_clock::now();
    auto t = t1 - t0;
    auto tmin = std::chrono::duration_cast<std::chrono::minutes> (t);
    auto tsec = std::chrono::duration_cast<std::chrono::seconds> (t);

    std::string min = tmin.count() + " minutes and ";
    std::string sec = tsec.count() + " seconds and ";

    return min+sec;
    
}

/**
 * Classe principal para a inicialização e execução do programa
 */
int main(int argc, char const *argv[])
{
    // Instanciando grafo de steiner
    SteinerGraph graph = SteinerGraph();
    
    // Leitura 
    // graph.readFromCin();

    // Testando saida
    // graph.printSteinerSet();
    // cout << endl;
    // graph.printTerminalSet();
    // cout << endl;
    // graph.printEdges();
    // cout << endl;

    // teste de tempo
    cout << duration() << endl;

    // escrevendo grafo em arquivo
    // graph.writeToFile("nat.txt");

    return 0;
}