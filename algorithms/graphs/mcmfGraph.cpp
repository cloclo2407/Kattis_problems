#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <vector>
#include <limits>

const long long INF_MAX = std::numeric_limits<long long>::max();

/*
* Edge class to represent edges with cost and capacity
*/
class Edge {
public:
    int u, v, capacity, cost;
    int flow = 0;

    Edge(int u, int v, int capacity, int cost) : u(u), v(v), capacity(capacity), cost(cost) {}
};

/*
* DirectedGraph class to represent a directed graph with edges with cost and capacity
 * adj_id: stores the index of edges in edges list for each node
 * number_of_nodes : stores the number of nodes in the graph
 * edges : list of edges with edge at index=0 mod 2 and reverse edge at index = 1 mod2
*/
class DirectedGraph {
    public:
    std::vector<std::vector<int>> adj_id; // contains id of edges in edges list
    int number_of_nodes;
    std::vector<Edge> edges; 

    DirectedGraph(int number_of_nodes) {
        adj_id.resize(number_of_nodes);
        this->number_of_nodes = number_of_nodes;
    }

    /*
    * Add edge to the graph. The edge is added as forward and reverse edges
    * reverse edge has an opposite cost
    */
    void addEdge(Edge edge) {
        adj_id[edge.u].push_back((int)edges.size());
        edges.push_back(edge);
        // Add reverse edge
        Edge reverse_edge(edge.v, edge.u, 0, -edge.cost);
        adj_id[edge.v].push_back((int)edges.size());
        edges.push_back(reverse_edge);
    }

};

#endif