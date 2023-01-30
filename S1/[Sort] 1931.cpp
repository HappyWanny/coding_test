#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> v1, pair<int, int> v2)
{
	if (v1.second == v2.second) return v1.first < v2.first;
	return v1.second < v2.second;
}

vector<pair<int, int>> v;
int main() {
	int N;
	scanf("%d", &N);

	int s_time, e_time;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s_time, &e_time);
		v.push_back({ s_time, e_time });
	}

	sort(v.begin(), v.end(), compare);

	int max = 1;
	int next = v[0].second;

	for (int i = 1; i < N; i++)
	{
		if (next <= v[i].first)
		{
			max++;
			next = v[i].second;
		}
	}

	cout << max;
}