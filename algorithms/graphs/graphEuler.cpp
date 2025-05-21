#include <vector>

using namespace std;

class GraphEuler {
    public:
    int number_of_nodes; 
    vector<int> in_degree, out_degree; 
    vector<vector<int>> adj;
  

    GraphEuler(int n) : number_of_nodes(n) { 
        adj.resize(n);
        in_degree.resize(number_of_nodes);
        out_degree.resize(number_of_nodes);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        out_degree[u]++;
        in_degree[v]++;
    }
};
