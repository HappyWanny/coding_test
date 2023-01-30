#include <iostream>
#include <algorithm>
#include <vector>

// https://yabmoons.tistory.com/112

using namespace std;

int arr[1000];
int dp[1000];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		if (dp[i] > max) max = dp[i];
	}

	cout << max;
}