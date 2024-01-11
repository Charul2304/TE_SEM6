
#include <iostream>
#include <queue>
#include<vector>
#include <queue>
using namespace std;


// class Islands{
// 	public: 
// 	int R;
// 	int C;
// 	vector<vector<int>>mat;
// 	vector<vector<int>>vis;

// void input()
// {
// 	cout<<"Enter Rows &Columns : "<<endl;
// 	cin>>R>>C;
// 	vector<int>temp(C , 0);

// 	for(int i =0;i<R;i++)
// 	{   
// 			mat.push_back(temp);
// 			vis.push_back(temp);
// 	}
// }
// bool isSafe(int i, int j)
			
// {
// 	return (i >= 0) && (i < R) && 
// 		(j >= 0) && (j < C) && 
// 		(mat[i][j] && !vis[i][j]);
// }

// void BFS(
// 		int si, int sj)
// {
// 	int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
// 	int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// 	queue<pair<int, int> > q;
// 	q.push(make_pair(si, sj));
// 	vis[si][sj] = true;

// 	while (!q.empty()) {

// 		int i = q.front().first;
// 		int j = q.front().second;
// 		q.pop();

// 		for (int k = 0; k < 8; k++) {
// 			if (isSafe( i + row[k],
// 					j + col[k])) {
// 			vis[i + row[k]][j + col[k]] = true;
// 			q.push(make_pair(i + row[k], j + col[k]));
// 			}
// 		}
// 	}
// }

// int countIslands()
// {
// 	// bool vis[R][C];
// 	// memset(vis, 0, sizeof(vis));

// 	int res = 0;
// 	for (int i = 0; i < R; i++) {
// 		for (int j = 0; j < C; j++) {
// 			if (mat[i][j] && !vis[i][j]) {
// 				BFS(i, j);
// 				res++;
// 			}
// 		}
// 	}

// 	return res;
// }


// };
class BFS_Count_Islands{
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
int main()
{
	Islands obj;
	obj.input();
	cout << obj.countIslands();

	return 0;
}
