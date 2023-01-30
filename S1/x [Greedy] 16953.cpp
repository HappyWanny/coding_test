#include <iostream>
#include <algorithm>
#include <vector>

// https://jaekwan.tistory.com/15

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int result = 1;

	while (true) {
		if (B == A) break;

		if (B < A) {
			result = -1;
			break;
		}

		if (B % 10 == 1)
		{
			B -= 1;
			B /= 10;
			result++;
		}

		else if (B % 2 == 0) {
			B /= 2;
			result++;
		}

		else {
			result = -1;
			break;
		}
	}

	cout << result;
}