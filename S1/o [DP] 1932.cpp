#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
            cin >> arr[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int around[2][2] = { {-1,-1}, {-1,0} };
    
    dp[0][0] = arr[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int left = -1;
            int right = -1;
            if (j + around[0][1] >= 0) left = dp[i - 1][j - 1];
            if (j + around[1][1] < i)right = dp[i - 1][j];
            dp[i][j] = max(left, right) + arr[i][j];
        }
    }

    int dp_max = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[n - 1][i] > dp_max) dp_max = dp[n - 1][i];
    }

    cout << dp_max;
}