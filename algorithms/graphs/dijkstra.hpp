#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.hpp"
#include <vector>

/*
 * Implements Dijkstra's shortest path algorithm for a directed graph represented as an adjacency list.
 * Computes the shortest path from the source to all nodes
 * Assumes that the weights are non negative integers
 * Can work for classic dijkstra and for time-table 
 *
 * @param graph : The graph on which to perform Dijkstra's algorithm (DirectedGraph object)
 * @param source : The starting node for the shortest path (integer)
 *
 * @return A pair containing the shortest path distances from the source to all other nodes (vector<long long>) and the vector of previous nodes in the shortest paths
*/
std::pair<std::vector<long long>,std::vector<int>> dijkstra(DirectedGraph& graph, int source);

std::pair<std::vector<long long>,std::vector<int>> dijkstra(DirectedGraph& graph, vector<long long> &p, int source);

/*
 * Reconstruct the shortest path as a list of nodes from the source to node end
 *
 * @param previous: The predecessor vector for reconstructing the path (vector of int), obtained with bellmanFord function
 * @param end: The end node (an int), we want the path from source to end
 *
 * @return A vector containing the nodes in the shortest path from the source to the end node (vector of int)
*/std::vector<int> reconstructPath(std::vector<int> &previous, int end);

#endif