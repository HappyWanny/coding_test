#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<pair<int, int>> start;
    vector<vector<int>> tomato(N, vector<int>(M));
    queue<pair<int, int>> q;
    vector<vector<int>> visited(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int t;
            cin >> t;
            if (t == 1)
            {
                q.push({ i,j });
                visited[i][j]++;
            }
            tomato[i][j] = t;
        }
    }
    
    vector<pair<int, int>> adj = { {-1, 0}, {0, -1},{0,1},{1,0} };
    while (!q.empty())
    {
        int v[2];
        v[0] = q.front().first;
        v[1] = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int adj_v0 = v[0] + adj[i].first;
            int adj_v1 = v[1] + adj[i].second;
            if (adj_v0 >= 0 && adj_v1 >= 0 && adj_v0 < N && adj_v1 < M && visited[adj_v0][adj_v1] == -1 && tomato[adj_v0][adj_v1] == 0)
            {
                q.push({ adj_v0, adj_v1 });
                visited[adj_v0][adj_v1] = visited[v[0]][v[1]] + 1;
            }
        }
    }

    
    bool flag = true;
    int max = -99;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == -1 && tomato[i][j] == 0)
            {
                flag = false;
                //break;
            }
            if (visited[i][j] > max) max = visited[i][j];
        }
    }

    if (flag == true) cout << max;
    else cout << -1;
}