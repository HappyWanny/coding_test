#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//https://ongveloper.tistory.com/328

int N;
int schedule[1500001][2];
int dp[1500001];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> schedule[i][0] >> schedule[i][1];
	}

	int temp = 0;
	for (int i = 1; i <= N + 1; i++) {
		temp = max(temp, dp[i]);

		if (i + schedule[i][0] > N + 1) continue;

		dp[i + schedule[i][0]] = max(dp[i + schedule[i][0]], schedule[i][1] + temp);
	}

	cout << temp;
}