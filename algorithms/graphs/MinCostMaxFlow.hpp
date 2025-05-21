#ifndef MCMF_H
#define MCMF_H

#include "mcmfGraph.cpp"
#include <algorithm>

/*
 * Implements the Min-Cost Max-Flow algorithm for a directed graph represented as an adjacency list and a list of edges
 * Computes the maximum flow and the minimum cost of a maximum flow from the source to the sink.
 * Works for graph with positive costs and weights
 *
 * @param graph : The graph on which to perform the Min-Cost Max-Flow algorithm (DirectedGraph object)
 * @param source : The starting node for the flow (integer)
 * @param sink : The sink node for the flow (integer)
*/
std::pair<int, int> min_cost_max_flow(DirectedGraph &graph, int source, int sink);

#endif