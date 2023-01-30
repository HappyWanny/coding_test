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

void dfs(vector<bool> &visit, vector<vector<int>> &a, int v)
{
	if (!visit[v])
	{
		visit[v] = 1;
		printf("%d ", v + 1);

		for (int i = 0; i < a[v].size(); i++)
		{
			if (!visit[a[v][i]]) dfs(visit, a, a[v][i]);
		}
	}
}

int main() {
	int N, M, V;
	// scanf("%d %d %d", &N, &M, &V);

	cin >> N >> M >> V;

	vector<vector<int>> adj(N);
	int x, y;
	for (int i = 0; i < M; i++)
	{
		//scanf("%d %d", &x, &y);
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}

	for (int i = 0; i < N; i++)
		sort(adj[i].begin(), adj[i].end());

	vector<bool> d_visit(N);
	dfs(d_visit, adj, V - 1);
	printf("\n");

	// BFS
	vector<int> b_visit(N);
	queue<int> q;
	q.push(V - 1);
	b_visit[V - 1] = 1;

	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();
		printf("%d ", vertex + 1);

		for (int i = 0; i < adj[vertex].size(); i++)
		{
			if (!b_visit[adj[vertex][i]])
			{
				q.push(adj[vertex][i]);
				b_visit[adj[vertex][i]] = 1;
			}
		}
	}
}