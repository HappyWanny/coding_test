#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
3 2
1 4
4 1
2 3
5 5

4 1 ok
3 2 ok 
2 3 ok 
1 4 ok
5 5

3 6
7 3
4 2
1 4
5 7
2 5
6 1

6 1 ok
4 2 ok
7 3 
1 4 ok
2 5 no
3 6 no
5 7 no
*/
bool compare(pair<int, int> v1, pair<int, int>v2)
{
	return v1.second < v2.second;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int N;
		scanf("%d", &N);

		int x, y;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &x, &y);
			v.push_back({ x, y });
		}

		sort(v.begin(), v.end(), compare);

		int cnt = 1;
		int idx = 0;
		for (int i = 1; i < N; i++)
			if (v[i].first < v[idx].first)
			{
				cnt++;
				idx = i;
			}

		printf("%d\n", cnt);
	}
}