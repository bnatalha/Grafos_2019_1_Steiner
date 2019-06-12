#ifndef SRC_DIJKSTRA_HPP
#define SRC_DIJKSTRA_HPP

#include "SteinerGraph.hpp"

class Dijkstra
{
private:
  SteinerGraph inputGraph;
  std::string minutes;
  std::string seconds;
public:
  explicit Dijkstra(SteinerGraph &);
  ~Dijkstra();

  void run();
};

#endif //SRC_DIJKSTRA_HPP
