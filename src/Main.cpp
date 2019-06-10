#include <iomanip>
#include <iostream>
#include <vector>

#include "Edge.hpp"

using namespace std;

/**
 * Classe principal para a inicialização e execução do programa
 */
int main(int argc, char const *argv[])
{
    std::unordered_set<int> steiner, terminal;

    std::vector<Edge> edges;

    int steinerCount, terminalCount, edgesCount;
    std::cin >> steinerCount >> terminalCount >> edgesCount;

    int totalVertices = steinerCount + terminalCount + 1;

    vector< vector<int> > matrix (totalVertices);
    for(int i = 0; i < totalVertices; i++){
        matrix[i].resize(totalVertices, -1);
        matrix[i][i] = 0;
    }
    
    for (int i = 0; i < edgesCount; i++){
        int o, d, c;
        std::cin >> o >> d >> c;

        matrix[o][d] = matrix[d][o] = c;
        matrix[0][o] = matrix[o][0] = 0;
        steiner.insert(o);
        terminal.insert(d);

        

        Edge newEdge(o, d, c);

        edges.push_back(newEdge);
    }

    std::cout << std::endl;
    std::cout << "Steiner: ";
    for (int s : steiner){
        std::cout << s << " ";
    }
    std::cout << std::endl
              << std::endl;
    
    std::cout << "Terminal: ";
    for (int t : terminal){
        std::cout << t << " ";
    }
    std::cout << std::endl
              << std::endl;

    for (Edge e : edges){
        std::cout << e << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < totalVertices; i++){
        for (int j = 0; j < totalVertices; j++){
            std::cout << setfill(' ') << setw(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
