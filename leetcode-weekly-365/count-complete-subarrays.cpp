#include <bits/stdc++.h>
using namespace std;

int countCompleteSubarrays(vector<int> &nums)
{
    unordered_map<int, int> ft;
    for (int i : nums)
    {
        ft[i]++;
    }

    int target = ft.size();

    // Sliding Window Logic
    int i = 0;
    int j = 0;
    int n = nums.size();
    unordered_map<int, int> temp;
    int res = 0;
    while (j <= n)
    {
        if (temp.size() == target)
        {
            while (temp.size() == target)
            {
                res += n - j + 1;
                temp[nums[i]]--;
                if (temp[nums[i]] == 0)
                {
                    temp.erase(nums[i]);
                }
                i++;
            }
        }
        else
        {
            if (j < n)
            {
                temp[nums[j]]++;
                j++;
            }
            else
            {
                break;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    cout << countCompleteSubarrays(a);
}