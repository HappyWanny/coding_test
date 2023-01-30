#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int arr[100001];
int dp[100001][3]; // 0은 최대값 1은 앞뒤값 2는 지금까지 다 더한값, 근데 2는 양수가 나올경우 초기화됨

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];


    dp[0][0] = arr[0]; dp[0][1] = arr[0]; dp[0][2] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][1] = arr[i - 1] + arr[i];
        dp[i][2] = max(dp[i - 1][2] + arr[i], arr[i]);
        //else dp[i][2] = dp[i - 1][2] + arr[i];
        dp[i][0] = max({ dp[i - 1][0],dp[i][1], dp[i][2] });
    }

    cout << dp[n - 1][0];
}