#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int pay[1001];
int dp[1001];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> pay[i];

	dp[1] = pay[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], pay[j] + dp[i - j]);
		}
	}

	cout << dp[N];
}