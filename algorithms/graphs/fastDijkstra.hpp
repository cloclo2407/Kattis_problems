#ifndef F_DIJSTRA
#define F_DIJSTRA

#include "mcmfGraph.cpp"
#include <vector>

using namespace std;

/*
 * Implements Dijkstra's shortest path algorithm for a directed graph represented as an adjacency list and a list of edges
 * Computes the shortest path from the source to all nodes
 *
 * @param graph : The graph on which to perform Dijkstra's algorithm (DirectedGraph object)
 * @param potential : The potential vector from the min-cost max-flow algorithm
 * @param source : The starting node for the shortest path (integer)
 * 
 * return : pair with a vector of the distances from source to nodes and a list with previous nodes in the shortest paths
*/
pair<vector<long long>, vector<int>> dijkstra(const DirectedGraph &graph, const vector<long long> &potential, int source) ;

#endif
