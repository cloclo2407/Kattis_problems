#ifndef GRAPH_H
#define GRAPH_H

#include "edge.hpp"
#include <vector>

/*
 * A directed graph represented as an adjacency list.
 * Each node is represented as an integer, and each edge is represented as an Edge object.
 *
 * @param number_of_nodes: The number of nodes in the graph
 * @param adj : The adjacency list 
 *
 * @note This class assumes that the graph is directed
*/
class DirectedGraph {
    public:
    std::vector<std::vector<Edge>> adj; 
    int number_of_nodes; 

    /*
     * Constructor for the DirectedGraph class.
     *
     * @param number_of_nodes: The number of vertices in the graph
    */
    DirectedGraph(int number_of_nodes);

    /*
     * Add an edge to the graph by adding it to the adjacency list
     *
     * @param edge: The edge to be added to the graph (Edge object)
    */
    void addEdge(Edge edge);
};

#endif