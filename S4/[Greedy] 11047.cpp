#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    int N, K;
    cin >> N >> K;

    vector<int> coin(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }

    int cnt = 0;
    for (int i = N - 1; i > -1; i--)
    {
        if (coin[i] > K) continue;
        cnt += (K / coin[i]);
        K -= (K / coin[i]) * coin[i];
    }

    cout << cnt;
}