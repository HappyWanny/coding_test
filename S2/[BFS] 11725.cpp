#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> map[100001];
int parent[100001];
bool visited[100001];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		
		map[x].push_back(y);
		map[y].push_back(x);
	}

	// bfs
	queue<int> q;

	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();

		for (int i = 0; i < map[vertex].size(); i++)
		{
			if (!visited[map[vertex][i]])
			{
				visited[map[vertex][i]] = true;
				q.push(map[vertex][i]);
				parent[map[vertex][i]] = vertex;
			}
		}
	}

	for (int i = 2; i < N + 1; i++) cout << parent[i] << "\n";
}