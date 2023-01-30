#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int u, v;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<int> visited(N);
    queue<int> q;
    int cnt = 0;
    
    for (int j = 0; j < N; j++)
    {
        if (visited[j] == 0)
        {
            q.push(j);
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                visited[v] = 1;

                for (int i = 0; i < graph[v].size(); i++)
                {
                    if (visited[graph[v][i]] == 0)
                    {
                        q.push(graph[v][i]);
                        visited[graph[v][i]] = 1;
                    }
                }
            }
            cnt++;
        }
    }
    cout << cnt;
    
}