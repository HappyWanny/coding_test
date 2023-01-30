#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int M, N, H;
    cin >> M >> N >> H;
    
    vector<pair<int, pair<int, int>>> start;
    vector<vector<vector<int>>> tomato(H, vector<vector<int>> (N, vector<int>(M)));
    queue<pair<int, pair<int, int>>> q;
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M, -1)));

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int t;
                cin >> t;
                if (t == 1)
                {
                    q.push({ k,{i,j} });
                    visited[k][i][j]++;
                }
                tomato[k][i][j] = t;
            }
        }
    }

    vector<pair<int, pair<int, int>>> adj = { {-1,{0,0}},{1,{0,0}},{0,{ -1,0}},{0,{1,0}},{0,{0,-1}},{0,{0,1}} };
    while (!q.empty())
    {
        int v[3];
        v[0] = q.front().first;
        v[1] = q.front().second.first;
        v[2] = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int adj_v0 = v[0] + adj[i].first;
            int adj_v1 = v[1] + adj[i].second.first;
            int adj_v2 = v[2] + adj[i].second.second;

            if (adj_v0 >= 0 && adj_v1 >= 0 && adj_v2 >= 0 && adj_v0 < H && adj_v1 < N && adj_v2<M && visited[adj_v0][adj_v1][adj_v2] == -1 && tomato[adj_v0][adj_v1][adj_v2] == 0)
            {
                q.push({ adj_v0, {adj_v1,adj_v2 } });
                visited[adj_v0][adj_v1][adj_v2] = visited[v[0]][v[1]][v[2]] + 1;
            }
        }
    }

    
    bool flag = true;
    int max = -99;
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (visited[k][i][j] == -1 && tomato[k][i][j] == 0)
                {
                    flag = false;
                    //break;
                }
                if (visited[k][i][j] > max) max = visited[k][i][j];
            }
        }
    }

    if (flag == true) cout << max;
    else cout << -1;
}