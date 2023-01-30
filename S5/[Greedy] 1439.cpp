#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string S;
    cin >> S;

    int cnt = 0;
    for (int i = 0; i < S.size() - 1; i++)
    {
        if (S[i] != S[i + 1]) cnt++;
    }

    cout << (cnt+1) / 2;
}