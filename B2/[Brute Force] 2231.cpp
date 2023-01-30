#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int x, sum, s;
	int flag = 0;
	for (int i = 1; i <N; i++)
	{
		x = i;
		sum = x;
		while (x != 0)
		{
			s = x % 10;
			sum += s;
			x = x / 10;
		}

		if (sum == N)
		{
			printf("%d\n", i);
			flag = 1;
			break;
		}
	}

	if (flag == 0) printf("0");
}