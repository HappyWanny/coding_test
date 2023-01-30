#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

// https://chanhuiseok.github.io/posts/baek-13/

using namespace std;

int map[2188][2188];
int result[3];

bool check(int row, int col, int num) {
	int start = map[row][col];

	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j]) return false;
		}
	}

	return true;
}

void divide(int row, int col, int num) {
	if (check(row, col, num)) {
		result[map[row][col]]++;
	}
	else {
		int size = num / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(row + size * i, col + size * j, size);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;

	int n;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			n++;
			map[i][j] = n;
		}
	}

	divide(0, 0, N);
	cout << result[0] << " " << result[1] << " " << result[2];
}