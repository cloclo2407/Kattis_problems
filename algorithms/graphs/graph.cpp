#include "graph.hpp"

DirectedGraph::DirectedGraph(int number_of_nodes) {
    adj.resize(number_of_nodes);
    this->number_of_nodes = number_of_nodes;
}

void DirectedGraph::addEdge(Edge edge) {
    adj[edge.u].push_back(edge);
}