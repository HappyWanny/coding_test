#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> item(N, vector<int>(2));
    for (int i = 0; i < N; i++)
        cin >> item[i][0] >> item[i][1];

    //sort(item.begin(), item.end());

    vector<vector<int>> value(N + 1, vector<int>(K + 1, -1));
    for (int i = 0; i <= N; i++) value[i][0] = 0;
    for (int i = 0; i <= K; i++) value[0][i] = 0;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (item[i - 1][0] <= j)
            {
                value[i][j] = max(value[i - 1][j], item[i - 1][1] + value[i - 1][j - item[i - 1][0]]);
                // cout << value[i - 1][j] << " / " << item[i - 1][1] << " " << value[i - 1][j - item[i - 1][0]] << endl;
            }

            else
                value[i][j] = value[i - 1][j];
        }
    }

    /*
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= i_max; j++) cout << value[i][j] << " ";
        cout << endl;
    }*/

    cout << value[N][K];
}