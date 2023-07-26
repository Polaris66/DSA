/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &a)
    {
        sort(a.begin(), a.end());
        vector<vector<int>> res;

        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if ((i > 0) && (a[i] == a[i - 1]))
            {
                continue;
            }

            // Two Pointer
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = a[i] + a[j] + a[k];
                if (sum == 0)
                {
                    res.push_back({a[i], a[j], a[k]});
                    j++;
                    k--;
                    while ((j < k) && (a[j] == a[j - 1]))
                        j++;
                    while ((j < k) && (a[k] == a[k + 1]))
                        k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        return res;
    }
};
// @lc code=end
