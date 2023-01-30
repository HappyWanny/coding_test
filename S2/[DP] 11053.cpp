#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> cnt(N);
   // cnt[0] = 1;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        int nMax = 0;
        for (int j = 0; j <i;j++)
        {
            if (arr[j] < arr[i] && cnt[j] > nMax) nMax = cnt[j];
        }

        cnt[i] = nMax + 1;

        result = max(result, cnt[i]);
    }

    cout << result;
}

//https://hwan-shell.tistory.com/299