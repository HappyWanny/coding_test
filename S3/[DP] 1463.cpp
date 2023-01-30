#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> count(N, 0);
	count[0] = 0; // 최솟값 1은 연산 1번만 됨

	for (int i = 1; i < N; i++)
	{
		if ((i + 1) % 2 == 0) count[i] = count[(i + 1) / 2 - 1] + 1;

		if ((i + 1) % 3 == 0)
			count[i] = count[i] > 0 ? min(count[(i + 1) / 2 - 1] + 1, count[(i + 1) / 3 - 1] + 1) : min(count[(i + 1) / 3 - 1] + 1, count[i - 1] + 1);

		else
		{
			if (count[i] > 0) count[i] = min(count[(i + 1) / 2 - 1] + 1, count[i - 1] + 1);
			else count[i] = count[i - 1] + 1;
		}
	}
	cout << count[N - 1];
}