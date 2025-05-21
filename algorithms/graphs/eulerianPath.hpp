#ifndef EULERIAN_PATH_H
#define EULERIAN_PATH_H

#include "graphEuler.cpp"

/*
 * Checks if a graph has an Eulerian path. 
 * If yes, return true and set startNode as a possible starting point. Otherwise, return false and set startNode as -1
 *
 * @param graph : The graph to check for Eulerian path (DirectedGraph object)
 * @param startNode : Where a possible starting point of the path is going to be stored
 *
 * @return True if the graph has an Eulerian path, false otherwise.
 *         The start node of the Eulerian path is stored in the variable startNode.
*/
bool isEulerianPathPossible(GraphEuler &graph, int &startNode);

/*
 * Finds a node that has at least one edge in the graph
 *
 * @param graph : The graph to check for non-empty nodes (GraphEuler object)
 *
 */
int findNonEmptyNode(GraphEuler &graph);

/*
 * Finds an Eulerian path in a graph using Depth-First Search (DFS) algorithm
 *
 * @param graph : The graph to find the Eulerian path (GraphEuler object)
 * @param startNode : The starting node for the DFS algorithm (integer)
 * 
 * returns : The Eulerian path as a vector of integers
 */
vector<int> findEulerianPath(GraphEuler &graph, int startNode) ;

#endif