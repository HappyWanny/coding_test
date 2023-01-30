#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> arr;

int main() {
	int N;
	int x, y;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		arr.push_back({ x, y });
	}

	sort(arr.begin(), arr.end());

	
	for (int i = 0; i < arr.size(); i++)
		printf("%d %d\n", arr[i].first, arr[i].second);
}