#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int matrix[1025][1025];

int select(int x, int y)
{
	vector<int> arr;
	for (int i = x; i < x + 2; i++)
	{
		for (int j = y; j < y + 2; j++) arr.push_back(matrix[i][j]);
	}

	sort(arr.begin(), arr.end());

	return arr[2];
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) cin >> matrix[i][j];
	}

	while (N > 1)
	{
		for (int i = 0; i < N; i += 2)
		{
			for (int j = 0; j < N; j += 2)
			{
				matrix[i / 2][j / 2] = select(i, j);
			}
		}

		N /= 2;
	}

	cout << matrix[0][0];
}