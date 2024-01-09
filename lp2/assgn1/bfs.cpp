
#include <iostream>
#include <queue>
using namespace std;

#define R 5
#define C 5

bool isSafe(int mat[R][C], int i, int j,
			bool vis[R][C])
{
	return (i >= 0) && (i < R) && 
		(j >= 0) && (j < C) && 
		(mat[i][j] && !vis[i][j]);
}

void BFS(int mat[R][C], bool vis[R][C],
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
			if (isSafe(mat, i + row[k],
					j + col[k], vis)) {
			vis[i + row[k]][j + col[k]] = true;
			q.push(make_pair(i + row[k], j + col[k]));
			}
		}
	}
}

int countIslands(int mat[R][C])
{
	bool vis[R][C];
	memset(vis, 0, sizeof(vis));

	int res = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mat[i][j] && !vis[i][j]) {
				BFS(mat, vis, i, j);
				res++;
			}
		}
	}

	return res;
}

int main()
{
	int mat[][C] = { { 1, 1, 0, 0, 0 },
					{ 0, 1, 0, 0, 1 },
					{ 1, 0, 0, 1, 1 },
					{ 0, 0, 0, 0, 0 },
					{ 1, 0, 1, 0, 1 } };

	cout << countIslands(mat);

	return 0;
}
