#include "Edge.hpp"

Edge::Edge(int origin, int destination, int cost){
  this->origin = origin;
  this->destination = destination;
  this->cost = cost;
}

Edge::~Edge(){}

int const Edge::getOrigin(){
  return this->origin;
}

int const Edge::getDestination(){
  return this->destination;
}

int const Edge::getCost(){
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