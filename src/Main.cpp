#include <iostream>
#include <algorithm>

#include "Edge.hpp"

void edgeTest();

/**
 * Classe principal para a inicialização e execução do programa
 */
int main(int argc, char const *argv[]){
  std::unordered_set<int> steiner, terminal;

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++){
    int o, d, c;
    std::cin >> o >> d >> c;

    steiner.insert(o);
    terminal.insert(d);

    Edge *e1 = new Edge(o, d, c);
    
    std::cout << *e1 << std::endl;

    if(e1){
      delete e1;
    }
  }

  std::cout << "Steiner: ";
  for(int s : steiner){
    std::cout << s << " ";
  }
  std::cout << std::endl;

  std::cout << "Terminal: ";
  for(int t : terminal){
    std::cout << t << " ";
  }
  std::cout << std::endl;

  return 0;
}

void edgeTest(){
  Edge e1(0, 1, 5), e2(0, 2, 9);

  std::cout << "E1: " << e1 << std::endl;
  std::cout << "E2: " << e2 << std::endl;

  std::cout << "E1 > E2 " << (e1 > e2 ? "(sim)" : "(não)") << std::endl;
  std::cout << "E1 < E2 " << (e1 < e2 ? "(sim)" : "(não)") << std::endl;
}