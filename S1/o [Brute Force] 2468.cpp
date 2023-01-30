#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    int max_H = 1;
    int min_H = 100;
    vector<vector<int>> area(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            if (a > max_H) max_H = a;
            if (a < min_H) min_H = a;
            area[i][j] = a;
        }
    }

    int H;
    int max = 0;
    vector<pair<int,int>> around = { {-1,0},{0,-1},{1,0},{0,1} };
    for (int i = 0; i <= max_H; i++)
    {
        H = i;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(N, vector<int>(N));

        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (area[j][k] > H && visited[j][k] == 0)
                {
                    cnt++;
                    q.push({ j,k });
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        visited[x][y] = 1;
                        q.pop();
                        //cout << x << " " << y << " " << H << endl;

                        for (int l = 0; l < 4; l++)
                        {
                            int around_x = x + around[l].first;
                            int around_y = y + around[l].second;

                            if (around_x >= 0 && around_y >= 0 && around_x < N && around_y < N)
                            {   
                                if (visited[around_x][around_y] == 0 && area[around_x][around_y] > H)
                                {
                                    q.push({ around_x, around_y });
                                    visited[around_x][around_y] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (cnt > max) max = cnt;

    }
    //max = (N * N) - max;
    cout << max;
}