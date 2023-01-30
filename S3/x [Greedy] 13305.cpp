#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dist[100000];
int cost[100000];

// https://excited-hyun.tistory.com/71
int main()
{
	int N;
	cin >> N;

	for (int i = 1; i < N; i++) cin >> dist[i];
	for (int i = 0; i < N; i++) cin >> cost[i];

	long long tmp_cost = 0;
	long long total = 0;

	// 첫 번째 -> 두 번째로 이동
	tmp_cost = cost[0];
	total = tmp_cost * dist[1];

	for (int i = 1; i < N; i++)
	{
		if (tmp_cost > cost[i]) tmp_cost = cost[i];

		total += tmp_cost * dist[i + 1];
	}

	cout << total << endl;
}