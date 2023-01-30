#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	int T;
	int M, N, K;
	cin >> T;

	for (int t = 0; t < T; t++)
	{	
		cin >> M >> N >> K;

		int x, y;
		int pos[50][50];
		bool visited[50][50];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				pos[i][j] == 0;
				visited[i][j] == false;
			}
		}

		for (int i = 0; i < K; i++)
		{
			cin >> y >> x;
			pos[x][y] = 1;
		}

		int cnt = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (pos[i][j] == 1 && !visited[i][j])
				{
					q.push({ i, j });
					while (!q.empty())
					{
						int a = q.front().first;
						int b = q.front().second;
						q.pop();
						visited[a][b] = true;

						vector<pair<int, int>> adj = { {-1, 0}, {1,0}, {0, 1}, {0, -1} };
						for (int l = 0; l < 4; l++)
						{
							int adj_x = a + adj[l].first;
							int adj_y = b + adj[l].second;
							if (adj_x >= 0 && adj_y >= 0 && adj_x < N && adj_y < M && !visited[adj_x][adj_y] && pos[adj_x][adj_y] == 1)
							{
								visited[adj_x][adj_y] = true;
								q.push({ adj_x,adj_y });
							}
						}
					}
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}
}