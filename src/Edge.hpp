#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include <iostream>
#include <unordered_set>

class Edge {
private:
  int origin, destination, cost;
public:
  Edge(int, int, int);
  ~Edge();

  int const getOrigin();
  int const getDestination();
  int const getCost();

  friend bool operator>(Edge const &, Edge const &);
  friend bool operator<(Edge const &, Edge const &);
  friend std::ostream &operator<<(std::ostream &, const Edge &);
};

#endif // _EDGE_HPP_