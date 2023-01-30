#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool is_first()
{

}

int main() {
	int N;
	scanf("%d", &N);

	int x;
	int avg = 0;
	int most = -4001;
	int center, range;
	vector<int> v;
	vector<int> num(8001, 0);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		avg += x;
		v.push_back(x);
		
		num[x + 4000]++;
	}

	avg = round((float)avg / N);
	sort(v.begin(), v.end());
	center = v[(N - 1) / 2];

	/*
	int cnt = 0;
	int max = 2;
	for (int i = 0; i < 8002; i++)
	{
		if (num[i] >= max && cnt <= 2)
		{
			max = num[i];
			cout << "max " << i - 4000 << " " <<endl;
			most = (i - 4000);
			if (num[i] == max) cnt++;
		}
	}*/

	/*int cnt = 0;
	int max = 1;
	for (int i = 0; i < N; i++)
	{
		if (num[v[i] + 4000] >= max && cnt < 2)
		{
			if (num[v[i] + 4000] == max) cnt++;
			else cnt--;

			max = num[v[i] + 4000];
			most = v[i];
		}
	}
	*/

	int cnt = 0;
	int max = 1;
	for (int i = 0; i < N; i++)
	{
		cout << num[v[i] + 4000] << endl;
		if (num[v[i] + 4000] == 1) continue;
		else if (num[v[i] + 4000] > max)
		{
			max = num[v[i] + 4000];
			most = v[i];
			cnt = 0;
		}

		else if (num[v[i] + 4000] == max) cnt++;

		if (cnt == 2) break;
	}

	if (max == 1) most = v[1];
	range = v[N-1] - v[0];
	printf("%d\n%d\n%d\n%d", avg, center, most, range);
}