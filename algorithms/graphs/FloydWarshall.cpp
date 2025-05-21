#include "FloydWarshall.hpp"

#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

const long long INF_MAX = numeric_limits<long long>::max();
const long long INF_MIN = numeric_limits<long long>::min();

vector<vector<long long>> shortest_path_all_pairs(DirectedGraph& graph) {
    int n = graph.number_of_nodes;
    vector<vector<long long>> distance(n, vector<long long>(n, INF_MAX));
    for (int i = 0; i < n; ++i) {
        for (const auto edge : graph.adj[i]){
            if (edge.weight < distance[i][edge.v]){
                distance[i][edge.v] = edge.weight;
            }
        }
        distance[i][i] = 0;
    }
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INF_MAX && distance[k][j] != INF_MAX) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (distance[i][i] < 0) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][j] != INF_MAX) {
                    distance[i][j] = INF_MIN;
                }
            }
        }
    }
    
    for (int k = 0; k < n; ++k) {
        if (distance[k][k] < 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (distance[i][k] != INF_MAX && distance[k][j] != INF_MAX) {
                        distance[i][j] = INF_MIN;
                    }
                }
            }
        }
    }
    
    return distance;
}