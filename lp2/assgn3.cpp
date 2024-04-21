#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Node {
public:
    int vertex, key;
};

class Compare {
public:
    bool operator()(const Node& a, const Node& b) {
        return a.key > b.key;
    }
};

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        adj[src].push_back(make_pair(dest, weight));
        adj[dest].push_back(make_pair(src, weight)); // For undirected graph
    }

    void primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        priority_queue<Node, vector<Node>, Compare> pq;

        int src = 0;
        pq.push({src, 0});
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().vertex;
            pq.pop();

            inMST[u] = true;

            for (auto& pair : adj[u]) {
                int v = pair.first;
                int weight = pair.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({v, key[v]});
                    parent[v] = u;
                }
            }
        }

        cout << "Edge   Weight\n";
        int totalWeight = 0;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << "    " << key[i] << "\n";
            totalWeight += key[i];
        }
        cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    graph.primMST();

    return 0;
}
