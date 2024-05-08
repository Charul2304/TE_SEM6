#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void Union(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Kruskal {
public:
    int spanningTree(int V, vector<vector<pair<int, int>>>& adj, vector<pair<int, int>>& mstEdges) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it.first; // Corrected
                int wt = it.second;     // Corrected
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.Union(u, v);
                mstEdges.push_back({u, v});
            }
        }

        return mstWt;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V); // Corrected
    cout << "Enter the edges (format: source destination weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        adj[src].push_back({dest, weight}); // Corrected
        adj[dest].push_back({src, weight}); // Corrected
    }

    Kruskal obj;
    vector<pair<int, int>> mstEdges;
    int mstWt = obj.spanningTree(V, adj, mstEdges);
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << mstWt << endl;

    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (auto edge : mstEdges) {
        cout << edge.first << " -- " << edge.second << endl;
    }

    return 0;
}