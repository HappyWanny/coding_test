#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int k = 0; k < T; k++)
    {
        int l;
        cin >> l;
        vector<vector<int>> chess(l, vector<int>(l));

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        queue<pair<int, int>> q;
        vector<vector<int>> visited(l, vector<int>(l));
        vector<pair<int, int>> move = { {-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2} ,{-1,2},{-2,1} };
        vector<vector<int>> height(l, vector<int>(l));
        q.push({ x1, y1 });

        while (!q.empty())
        {
            int pos[2];
            pos[0] = q.front().first;
            pos[1] = q.front().second;
            if (visited[x2][y2] == 1) break;
            q.pop();
            visited[pos[0]][pos[1]] = 1;

            for (int i = 0; i < 8; i++)
            {
                int move_x = pos[0] + move[i].first;
                int move_y = pos[1] + move[i].second;

                if (move_x >= 0 && move_y >= 0 && move_x < l && move_y < l)
                {
                    if (visited[move_x][move_y] == 0)
                    {
                        visited[move_x][move_y] = 1;
                        q.push({ move_x, move_y });
                        height[move_x][move_y] = height[pos[0]][pos[1]] + 1;
                    }
                }
            }
        }

        cout << height[x2][y2] << "\n";
    }
}