#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, p_max = 0;
int schedule[15][2];

void profit(int day, int p)
{
    if (p > p_max) p_max = p;
    for (int i = day; i < N; i++)
    {
        if (schedule[i][0] + i > N) continue;
        // cout << i << endl;
        profit(schedule[i][0] + i, p + schedule[i][1]);
    }

    return;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> schedule[i][0] >> schedule[i][1];
    
    for (int j = 0; j < N; j++)
    {
        if (schedule[j][0] + j > N) continue;
        // cout << j << " " << schedule[j][0] << endl;
        profit(schedule[j][0] + j, schedule[j][1]);
    }

    cout << p_max;
}