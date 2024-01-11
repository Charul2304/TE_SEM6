#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Islands{
	public: 
	int R;
	int C;
	vector<vector<int>>mat;
	vector<vector<int>>vis;

void input()
{
	cout<<"Enter Rows &Columns : "<<endl;
	cin>>R>>C;
	vector<int>temp(C , 0);

	for(int i =0;i<R;i++)
	{   
			mat.push_back(temp);
			vis.push_back(temp);
	}
	
	for(int i =0;i<R;i++)
	{
	    for(int j=0;j<C;j++)
	    {
	       cout<<"Enter values for"<<i<<" & "<<j<<": ";
	       cin>>mat[i][j];
	    }
	}
}
bool isSafe(int i, int j)
			
{
	return (i >= 0) && (i < R) && 
		(j >= 0) && (j < C) && 
		(mat[i][j] && !vis[i][j]);
}

void BFS(
		int si, int sj)
{
	int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	queue<pair<int, int> > q;
	q.push(make_pair(si, sj));
	vis[si][sj] = true;

	while (!q.empty()) {

		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			if (isSafe( i + row[k],
					j + col[k])) {
			vis[i + row[k]][j + col[k]] = true;
			q.push(make_pair(i + row[k], j + col[k]));
			}
		}
	}
}

int countIslands()
{
	// bool vis[R][C];
	// memset(vis, 0, sizeof(vis));

	int res = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mat[i][j] && !vis[i][j]) {
				BFS(i, j);
				res++;
			}
		}
	}

	return res;
}


};
class DFS{

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

int main(){
    int c;
    cout<<"****************MENU*****************"<<endl;
    cout<<"1. DFS "<<endl;
    cout<<"2. BFS "<<endl;
    cout<<"Enter operation to perform"<<endl;
    int t;
    cin>>t;
    while(true)
{
    if(t==1){
    int V, E;
    cout << "Enter No. of Vertices and Edges" << endl;
    cin >> V >> E;
    vector<int> adj[V];
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS obj;
    bool ans = obj.isCycle(V, adj);
    if (ans) {
        cout << "Cycle Detected";
    } else {
        cout << "No Cycle Detected";
    }
    }

    else if(t==2){
    Islands obj1;
    obj1.input();
    cout << "No of Islands are : " << obj1.countIslands();
    }


}
return 0;


}
