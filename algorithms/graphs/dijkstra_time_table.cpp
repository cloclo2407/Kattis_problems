#include "graph.hpp"
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

const long long INF_MAX = numeric_limits<long long>::max();

/*
 * Dijkstra's algorithm for time-table shortest paths
 * Assumes that the weights are positive intergers
 * Works for edges(u,v,t0,P,d) with 
 * t0 : first time the edge is available
 * P : frequence at which the edge is available
 * d : time to traverse the edge
 *
 * @param graph The directed graph.
 * @param start The starting node.
 * @return A pair containing the shortest distances from the start node to each node and the previous node on the shortest path from the start to each node.
 * 
*/
pair<vector<long long>, vector<int>> dijkstra(DirectedGraph &graph, int start) {
    int n = graph.number_of_nodes;
    vector<long long> distances(n, INF_MAX);
    vector<int> previous(n, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
    distances[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [curTime, u] = pq.top();
        pq.pop();
        
        if (curTime > distances[u]) continue;
        
        for (const auto &edge : graph.adj[u]) {
            int waitTime;

            if (curTime <= edge.t0){
                waitTime = edge.t0 - curTime;
            }
            else if (edge.P == 0){
                continue;
            }
            else if ((curTime - edge.t0) % edge.P == 0) {
                waitTime = 0;
            }
            else {
                waitTime = edge.P - (curTime - edge.t0) % edge.P;
            }
            
            int newTime = curTime + waitTime + edge.d;
            if (newTime < distances[edge.v]) {
                distances[edge.v] = newTime;
                previous[edge.v] = edge.u;
                pq.push({newTime, edge.v});
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
