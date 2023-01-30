#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

// https://hagisilecoding.tistory.com/14

using namespace std;

int N, r, c;
int result = 0;

void dc(int x, int y, int size) {
	if (c == x && r == y) {
		cout << result;
		return;
	}
	else if (c < x + size && r < y + size && c >= x && r >= y) {
		dc(x, y, size / 2);
		dc(x + size / 2, y, size / 2);
		dc(x, y + size / 2, size / 2);
		dc(x + size / 2, y + size / 2, size / 2);
	}
	else {
		result += size * size;
	}
}

int main()
{
	cin >> N >> r >> c;

	dc(0, 0, pow(2, N));
}