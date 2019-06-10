#include <iostream>

#include "Edge.hpp"

void edgeTest();

/**
 * Classe principal para a inicialização e execução do programa
 */
int main(int argc, char const *argv[])
{
  std::cout << "MainApp" << std::endl;

  edgeTest();

  return 0;
}

void edgeTest(){
  Edge e1(0, 1, 5), e2(0, 2, 9);

  std::cout << "E1: " << e1 << std::endl;
  std::cout << "E2: " << e2 << std::endl;

  std::cout << "E1 > E2 " << (e1 > e2 ? "(sim)" : "(não)") << std::endl;
  std::cout << "E1 < E2 " << (e1 < e2 ? "(sim)" : "(não)") << std::endl;
}