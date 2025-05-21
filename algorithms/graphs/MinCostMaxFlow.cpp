#include "MinCostMaxFlow.hpp"
#include "fastDijkstra.hpp"
#include <algorithm>
#include <climits>


using namespace std;

pair<int, int> min_cost_max_flow(DirectedGraph &graph, int source, int sink) {
    int n = graph.number_of_nodes;

    // Initialize potential function
    vector<long long> potential(n, 0); 

    // Run Bellman-Ford once to initialize potentials
    for (int iter = 0; iter < n - 1; ++iter) {
        for (int u = 0; u < n; ++u) {
            for (int edge_id : graph.adj_id[u]) {
                const Edge &edge = graph.edges[edge_id];
                if (edge.capacity > 0 && potential[edge.v] > potential[u] + edge.cost) {
                    potential[edge.v] = potential[u] + edge.cost;
                }
            }
        }
    }

    int total_flow = 0, total_cost = 0;

    while (true) {
        // Use Dijkstra with potential function to find shortest path
        auto [distances, previous] = dijkstra(graph, potential, source);
        if (distances[sink] == INF_MAX) break;  // No more augmenting paths

        // Update potentials
        for (int i = 0; i < n; ++i) {
            if (distances[i] != INF_MAX) {
                potential[i] += distances[i];
            }
        }

        // Find bottleneck capacity (smallest residual capacity along the path)
        int bottleneck = INT_MAX;
        for (int v = sink; v != source; v = graph.edges[previous[v] ^ 1].v) {
            int edge_id = previous[v];
            bottleneck = min(bottleneck, graph.edges[edge_id].capacity - graph.edges[edge_id].flow);
        }

        // Augment flow and update residual capacities
        for (int v = sink; v != source; v = graph.edges[previous[v] ^ 1].v) {
            int edge_id = previous[v];
            graph.edges[edge_id].flow += bottleneck;
            graph.edges[edge_id ^ 1].flow -= bottleneck;
        }

        // Update total flow and cost incrementally
        total_flow += bottleneck;
        total_cost += bottleneck * (potential[sink] - potential[source]);
    }

    return {total_flow, total_cost};
}