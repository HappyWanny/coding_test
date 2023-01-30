#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> RGB(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        RGB[i][0] = a; RGB[i][1] = b; RGB[i][2] = c;
    }

    vector<vector<int>> cost(N, vector<int>(3));
    cost[0][0] = RGB[0][0]; cost[0][1] = RGB[0][1]; cost[0][2] = RGB[0][2];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0) cost[i][j] = min(cost[i - 1][1], cost[i - 1][2]) + RGB[i][j];
            else if (j == 1) cost[i][j] = min(cost[i - 1][0], cost[i - 1][2]) + RGB[i][j];
            else if (j == 2) cost[i][j] = min(cost[i - 1][0], cost[i - 1][1]) + RGB[i][j];
        }
    }

    cout << min({ cost[N - 1][0],cost[N - 1][1] ,cost[N - 1][2] });
}