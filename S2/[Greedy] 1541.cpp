#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string nums;
    cin >> nums;
    
    int result = 0;
    bool flag = false;
    string n;
    for (int i = 0; i <= nums.size(); i++)
    {
        if (nums[i] == '+' || nums[i] == '-' || i == nums.size())
        {
            if (flag == true) result -= atoi(n.c_str());
            else result += atoi(n.c_str());

            n = "";
        }

        else n += nums[i];

        if (nums[i] == '-') flag = true;
    }

    cout << result;
}