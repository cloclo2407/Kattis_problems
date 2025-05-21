#include "bellmanFord.hpp"
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

const long long INF_MAX = numeric_limits<long long>::max();
const long long INF_MIN = numeric_limits<long long>::min();

pair<vector<long long>,vector<int>> bellmanFord(DirectedGraph &graph, int start) {
    int n = graph.number_of_nodes;
    vector<long long> distances(n,INF_MAX);
    distances[start] = 0;
    vector<int> previous(n, -1);
    for (int i = 1; i<= n-1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (const auto &edge : graph.adj[j]) {
                int u = edge.u;
                int v = edge.v;
                long long weight = edge.weight;
                if (distances[u]!=INF_MAX && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    previous[v] = u;
                }
            }
        }
    }
    // Check for negative-weight cycles

    queue<int> negativeQueue;
    vector<bool> negativeCycle(n, false);

    for (int i = 0; i < n; i++) {
        for (auto &edge : graph.adj[i]) {
            int u = edge.u;
            int v = edge.v;
            long long weight = edge.weight;
            if (distances[u]!=INF_MAX && distances[u] + weight < distances[v]) {
                negativeQueue.push(v);
            }
        }
    }

    while (!negativeQueue.empty()) {
        int node = negativeQueue.front();
        negativeQueue.pop();
        negativeCycle[node] = true;
        for (int i = 0; i < n ; i++){
            for (const auto &edge : graph.adj[i]) {
                int u = edge.u;
                int v = edge.v;
                long long weight = edge.weight;
                if (u == node && !negativeCycle[v]) {
                    negativeQueue.push(v);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (negativeCycle[i]) {
            distances[i] = INF_MIN; // Set distance to negative infinity for negative cycle
        }
    }

    return make_pair(distances, previous);
}

vector<int> reconstructPath(const vector<int> &previous, int end) {
    vector<int> path;
    for (int node = end; node!= -1; node = previous[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());
    return path;
}