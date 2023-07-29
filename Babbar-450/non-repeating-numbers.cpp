#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums)
{
    int val = 0;
    for (int ele : nums)
    {
        val ^= ele;
    }

    int mask = val & (-val); // Returns Rightmost Set Bit
    int x = 0;
    int y = 0;
    for (int ele : nums)
    {
        if (ele & mask)
        {
            x ^= ele;
        }
        else
        {
            y ^= ele;
        }
    }

    return {min(x, y), max(x, y)};
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(2 * n + 2);

    for (auto &x : nums)
    {
        cin >> x;
    }

    vector<int> res = singleNumber(nums);
    cout << res[0] << " " << res[1] << endl;
}