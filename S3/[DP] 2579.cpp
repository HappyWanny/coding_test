#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> score(N);
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}

	vector<int> dp(N);
	dp[0] = score[0];
	if (N > 1) dp[1] = score[0] + score[1];

	// 어떻게 하면 세칸을 연속해서 밟지못하도록 할까
	if (N > 2)
		for (int i = 2; i < N; i++)
			dp[i] = max(dp[i - 3] + score[i - 1], dp[i - 2]) + score[i];

	cout << dp[N - 1];
}