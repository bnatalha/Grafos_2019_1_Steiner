#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include <unordered_set>

class Edge {
private:
  int origin, destination, cost;
public:
  Edge(int, int, int);
  ~Edge();

  int getOrigin();
  int getDestination();
  int getCost();

  friend bool operator>(Edge const &, Edge const &);
  friend bool operator<(Edge const &, Edge const &);
  friend std::ostream &operator<<(std::ostream &, const Edge &);
};

#endif //EDGE_HPP
