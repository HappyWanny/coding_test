#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> deliver(N, -1);
	deliver[2] = 1; // 3kg와 5kg는 1개씩만 가능
	deliver[4] = 1;

	for (int i = 5; i < N; i++)
	{
		if (deliver[i - 5] > 0) deliver[i] = deliver[i - 5] + 1;
		if (deliver[i - 3] > 0)
		{
			if (deliver[i] > 0) deliver[i] = min(deliver[i - 5] + 1, deliver[i - 3] + 1);
			else deliver[i] = deliver[i - 3] + 1;
		}
	}

	cout << deliver[N - 1];
}