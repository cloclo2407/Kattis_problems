#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "graph.hpp"
#include <vector>
#include <algorithm>

/*
 * Bellman-Ford algorithm to find the shortest path from a given source to all other nodes in a directed graph.
 * Find shortest paths from the source to all nodes in a directed graph
 * Works with integer weights that can be negative, works for negative cycles
 *
 * @param graph: The directed graph, has an adjancency list of edges (int u, int v, long long weight)
 * @param start: The source node (an int)
 *
 * @return A pair containing the shortest distances from the source to all other nodes (vector of long long) and the predecessor vector for reconstructing the path
*/
std::pair<std::vector<long long>,std::vector<int>> bellmanFord(DirectedGraph &graph, int start) ;

/*
 * Reconstruct the shortest path as a list of nodes from the source to node end
 *
 * @param previous: The predecessor vector for reconstructing the path (vector of int), obtained with bellmanFord function
 * @param end: The end node (an int), we want the path from source to end
 *
 * @return A vector containing the nodes in the shortest path from the source to the end node (vector of int)
*/
std::vector<int> reconstructPath(std::vector<int> &previous, int end);

#endif