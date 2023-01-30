#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M;
int map[1001][1001];
int dp[1001][1001];

int main() {
	cin >> N >> M;

	int x;
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> x;
			map[i][j] = x;
		}
	}

	int temp;
	int cnt = 0;
	dp[1][1] = map[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			temp = dp[i][j];

			dp[i + 1][j] = max(dp[i + 1][j], temp + map[i + 1][j]);
			dp[i][j + 1] = max(dp[i][j + 1], temp + map[i][j + 1]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], temp + map[i + 1][j + 1]);
		}
	}

	cout << dp[N][M];
}