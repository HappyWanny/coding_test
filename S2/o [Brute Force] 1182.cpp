#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int arr[20];
int N, S;
int cnt = 0;

void DFS(int n, int sum)
{
    if (sum == S) cnt++;

    for (int i = n; i < N; i++)
        DFS(i + 1, sum + arr[i]);

    if (n == N - 1) return;
}

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        DFS(i + 1, arr[i]);
    }

    cout << cnt;
}