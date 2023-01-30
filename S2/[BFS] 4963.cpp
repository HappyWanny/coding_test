#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	while (true)
	{
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0)break;

		vector<vector<int>> map(h, vector<int>(w));
		for (int i = 0; i < h; i++)
		{
			vector<int> row(w);
			int x;
			for (int j = 0; j < w; j++)
			{
				cin >> x;
				row[j] = x;
			}

			map[i] = row;
		}

		queue<pair<int, int>> q;
		vector<vector<int>> visited(h, vector<int>(w));
		vector<pair<int, int>> adj_xy = { {-1, -1} ,{-1, 0},{-1, 1},{0,-1},{0,1},{1, -1}, {1,0},{1, 1} };
		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					// bfs
					q.push({ i, j });

					while (!q.empty())
					{
						int pop_x = q.front().first;
						int pop_y = q.front().second;
						q.pop();
						visited[pop_x][pop_y] = 1;

						for (int k = 0; k < 8; k++)
						{
							int adj_x = pop_x + adj_xy[k].first;
							int adj_y = pop_y + adj_xy[k].second;

							if (adj_x < 0 || adj_y < 0 || adj_x >= h || adj_y >= w) continue;
							if (map[adj_x][adj_y] == 0) continue;
							if (visited[adj_x][adj_y] == 0)
							{
								visited[adj_x][adj_y] = 1;
								q.push({ adj_x, adj_y });
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