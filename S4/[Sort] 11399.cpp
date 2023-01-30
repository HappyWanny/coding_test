#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int x;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (v[i] * (N - i));
	}

	printf("%d", sum);

}