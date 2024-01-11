
// #include <iostream>
// #include <limits.h>
// #include <list>
// using namespace std;

// class Graph {

// 	int V;
// 	list<int>* adj;
// 	bool isCyclicUtil(int v, bool visited[], int parent);

// public:
	
// 	Graph(int V){
//         this->V = V;
// 	    adj = new list<int>[V];
//     }

// 	void addEdge(int v, int w){
//         adj[v].push_back(w);
// 	    adj[w].push_back(v);
//     }

// 	bool isCyclic(){
//         bool* visited = new bool[V];
// 	    for (int i = 0; i < V; i++)
// 		    visited[i] = false;

// 	    for (int u = 0; u < V; u++) {
// 		    if (!visited[u])
// 			    if (isCyclicUtil(u, visited, -1))
// 				    return true;
// 	        }
// 	    return false;
//     }

//     bool isCyclicUtil(int v, bool visited[], int parent)
//     {
// 	    visited[v] = true;
// 	    list<int>::iterator i;
// 	    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
// 		    if (!visited[*i]) {
// 			    if (isCyclicUtil(*i, visited, v))
// 				    return true;
// 		    }
// 		    else if (*i != parent)
// 			    return true;
// 	    }
// 	    return false;
//     }
// };

// int main()
// {
// 	Graph g1(5);
// 	g1.addEdge(1, 0);
// 	g1.addEdge(0, 2);
// 	g1.addEdge(2, 1);
// 	g1.addEdge(0, 3);
// 	g1.addEdge(3, 4);
// 	g1.isCyclic() ? cout << "Graph contains cycle\n"
// 				: cout << "Graph doesn't contain cycle\n";

// 	Graph g2(3);
// 	g2.addEdge(0, 1);
// 	g2.addEdge(1, 2);
// 	g2.isCyclic() ? cout << "Graph contains cycle\n"
// 				: cout << "Graph doesn't contain cycle\n";

// 	return 0;
// }

#include<iostream>
#include <vector>

using namespace std;

class Solution {

  public:
    bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkForCycle(it, node, vis, adj))
            return true;
        } else if (it != parent)
          return true;
      }

      return false;
    }
  public:
    bool isCycle(int V, vector < int > adj[]) {
      vector < int > vis(V + 1, 0);
      for (int i = 0; i < V; i++) {
        if (!vis[i]) {
          if (checkForCycle(i, -1, vis, adj)) return true;
        }
      }
	  return false;
    }
};

// { Driver Code Starts.
int main() {

  int V = 5;
  int E = 5;
  vector < int > adj[V];

  adj[0].push_back(1);
  adj[1].push_back(0);

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[1].push_back(4);
  adj[4].push_back(1);

  adj[4].push_back(3);
  adj[3].push_back(4);

  adj[2].push_back(3);
  adj[3].push_back(2);

  Solution obj;
  bool ans = obj.isCycle(V, adj);
  if (ans) {
    cout << "Cycle Detected";
	} else cout << "No Cycle Detected";

  return 0;
}	
