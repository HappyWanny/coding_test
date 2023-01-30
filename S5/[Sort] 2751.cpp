#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
void quick_sort(int i, int j)
{
	int left = i;
	int right = j;
	int pivot = (i + j) / 2;
	if (i >= j) return;

	while (left <= right) {
		while (arr[left] < arr[pivot]) left++;
		while (arr[right] > arr[pivot]) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	quick_sort(i, right);
	quick_sort(left, j);
}


int main() {
	int N;
	cin >> N;

	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		arr.push_back(n);
	}

	quick_sort(0, N-1);
	//sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) cout << arr[i] << "\n";
}