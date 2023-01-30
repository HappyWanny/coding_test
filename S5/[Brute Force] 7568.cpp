#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int x, y;
	vector<int> ranking(N, 1);
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
	}

	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				ranking[i]++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", ranking[i]);
	}

}