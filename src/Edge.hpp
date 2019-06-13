#ifndef SRC_EDGE_HPP_
#define SRC_EDGE_HPP_

#include <iostream>
#include <unordered_set>

class Edge {
private:
  int origin, destination;
  int cost; // 0 se a aresta não existe, 1 para arestas raiz - steiner, variado para arestas steiner - terminal.
public:
  Edge();
  Edge(int, int, int);
  ~Edge();

  int getOrigin();
  int getDestination();
  int getCost();

  friend bool operator>(Edge const &, Edge const &);
  friend bool operator<(Edge const &, Edge const &);
  friend std::ostream &operator<<(std::ostream &, const Edge &);
};

#endif // SRC_EDGE_HPP_
