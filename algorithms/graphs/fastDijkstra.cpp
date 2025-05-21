#include "fastDijkstra.hpp"
#include <queue>
#include <limits>

using namespace std;

pair<vector<long long>, vector<int>> dijkstra(const DirectedGraph &graph, const vector<long long> &potential, int source) {
    int n = graph.number_of_nodes;
    vector<long long> distances(n, INF_MAX);
    vector<int> previous(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int edge_id : graph.adj_id[u]) {
            const Edge &edge = graph.edges[edge_id];
            if (edge.flow < edge.capacity) {
                // Reweight the cost using the potential function
                long long reweighted_cost = edge.cost + potential[u] - potential[edge.v];
                if (distances[u] + reweighted_cost < distances[edge.v]) {
                    distances[edge.v] = distances[u] + reweighted_cost;
                    previous[edge.v] = edge_id;
                    pq.push({distances[edge.v], edge.v});
                }
            }
        }
    }

    return {distances, previous};
}