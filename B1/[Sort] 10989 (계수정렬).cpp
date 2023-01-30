#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int n;
	int arr[10001] = {0,};
	for (int i =0; i< N;i++){
		scanf("%d", &n);
		arr[n]++;
	}
	
	for (int i=1; i<10001; i++)
	{
		if (arr[i] != 0) {
			for (int j=0;j<arr[i];j++) printf("%d\n", i);
		}
	}
}