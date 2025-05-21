#include "graph.hpp"
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

const long long INF_MAX = numeric_limits<long long>::max();

// Classic Dijkstra
pair<vector<long long>,vector<int>> dijkstra(DirectedGraph &graph, int start) {
    int n = graph.number_of_nodes;
    vector<long long> distances(n, INF_MAX); // distances from start to each node
    distances[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> unvisited;
    unvisited.push({0, start});
    vector<int> previous(n, -1); // previous node on the shortest path from start to each node
    while (!unvisited.empty()) {
        int next = unvisited.top().second;
        int dist = unvisited.top().first;
        unvisited.pop();

        for (const auto &edge : graph.adj[next]) {
            int v = edge.v;
            long long distance = distances[next] + edge.weight;
            if (distance < distances[v]) { // Update distance if shorter path found
                distances[v] = distance;
                unvisited.push({distance, v});
                previous[v] = next;
            }
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
