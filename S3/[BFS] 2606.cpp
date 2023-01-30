#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

/*
인접행렬, 인접리스트로 관계 표현 후 탐색하면 되지 않을까
방문했는지 확인해야함, 큐 사용
*/
int main() {
	int N;
	scanf("%d", &N);
	vector<vector<int>> adj(N);

	int x, y;
	int pair;
	scanf("%d", &pair);
	for (int i = 0; i < pair; i++)
	{
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1); // 인접리스트로 연결
	}

	int cnt = 0;
	vector<int> visit(N);
	queue<int> q;

	visit[0] = 1;
	q.push(0);

	while (!q.empty())
	{
		int z = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < adj[z].size(); i++)
		{
			if (!visit[adj[z][i]])
			{
				q.push(adj[z][i]);
				visit[adj[z][i]] = 1;
			}
		}
	}
	cout << cnt - 1;
}