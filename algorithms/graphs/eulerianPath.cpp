#include "eulerianPath.hpp"
#include <stack>
#include <algorithm>

using namespace std;

bool isEulerianPathPossible(GraphEuler &graph, int &startNode) {
    int start = -1, end = -1;
    int start_count = 0, end_count = 0;

    for (int i = 0; i < graph.number_of_nodes; i++) {
        if (graph.out_degree[i] - graph.in_degree[i] == 1) { // one more leaving edge than entering edges
            start = i;
            start_count++; // has to be start of path
        } else if (graph.in_degree[i] - graph.out_degree[i] == 1) { // one more entering edge than leaving edges
            end = i;
            end_count++; // has to be end of path
        } else if (graph.in_degree[i] != graph.out_degree[i]) {
            return false; // no path
        }
    }

    if (start_count == 1 && end_count == 1) {
        startNode = start;
        return false;
    } else if (start_count == 0 && end_count == 0) {
        startNode = findNonEmptyNode(graph);
        return startNode != -1;
    }
    return false;
}

int findNonEmptyNode(GraphEuler &graph) {
    for (int i = 0; i < graph.number_of_nodes; i++) {
        if (!graph.adj[i].empty()) { // if at least one edge
            return i;
        }
    }
    return -1; // no edge found
}

vector<int> findEulerianPath(GraphEuler &graph, int startNode) {
    vector<int> path; // will contain eulerian path
    vector<int> edgeIndex(graph.number_of_nodes, 0); // contains index of next edge that has to be visited for each node
    stack<int> s;
    s.push(startNode);

    while (!s.empty()) {
        int v = s.top();
        if (edgeIndex[v] < graph.adj[v].size()) { 
            int next = graph.adj[v][edgeIndex[v]++];
            s.push(next);
        } else {
            path.push_back(v);
            s.pop();
        }
    }

    reverse(path.begin(), path.end());
    return path;
}