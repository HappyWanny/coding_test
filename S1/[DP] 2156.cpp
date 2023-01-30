#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (i > 3) dp[i] = max({ dp[i - 2], dp[i - 3] + arr[i - 1], arr[i - 1] + dp[i - 4] }) + arr[i];
        else if (i == 1) dp[1] = dp[0] + arr[1];
        else if (i == 2) dp[2] = max({ arr[0], arr[1] }) + arr[2];
        else if (i == 3) dp[3] = max({ dp[1], dp[0] + arr[2] }) + arr[3];
    }

    int max = -1;
    for (int i = 0; i < n; i++) if (dp[i] > max) max = dp[i];
    cout << max;
}