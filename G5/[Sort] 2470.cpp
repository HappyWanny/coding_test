#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*
-99 -2 -1 4 98

96
2
3

앞 뒤 값 비교해서 더한다음에 min값을 절대값으로 계산하며 개신하면될듯
*/

int main() {
	int N;
	scanf("%d", &N);

	vector<int>v(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	int left = 0;
	int right = N - 1;
	int min = 2000000000;
	vector<int> min_pair(2);

	while (left < right)
	{
		int sum = v[left] + v[right];

		if (abs(sum) < min)
		{
			min = abs(sum);
			min_pair[0] = v[left];
			min_pair[1] = v[right];

			if (sum == 0)break;
		}

		if (sum < 0) left++;
		else right--;
	}

	cout << min_pair[0] << " " << min_pair[1];

}