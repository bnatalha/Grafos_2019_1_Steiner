#include "Edge.hpp"

Edge::Edge() {}

Edge::Edge(int _origin, int _destination, int _cost){
  this->origin = _origin;
  this->destination = _destination;
  this->cost = _cost;
}

Edge::~Edge(){}

int Edge::getOrigin(){
  return this->origin;
}

int Edge::getDestination(){
  return this->destination;
}

int Edge::getCost(){
  return this->cost;
}

bool operator<(Edge const & a, Edge const & b){
  return a.cost < b.cost;
}

bool operator>(Edge const &a, Edge const &b){
  return a.cost > b.cost;
}

std::ostream &operator<<(std::ostream &os, const Edge &edge){
  os << "(" << edge.origin << ", " << edge.destination << ") : " << edge.cost;
  return os;
}
