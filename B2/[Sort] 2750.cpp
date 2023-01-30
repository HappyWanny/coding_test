#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;

	cin >> N;

	vector<int> arr;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		arr.push_back(n);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[i]) swap(arr[j], arr[i]);
		}
	}

	for (int i = 0; i < arr.size(); i++) cout << arr[i] << endl;
}