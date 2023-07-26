/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void permute(vector<int> &nums, int &n, vector<int> &curr, set<vector<int>> &S)
    {
        if (curr.size() == n)
        {
            S.insert(curr);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 11)
            {
                int temp = nums[i];
                nums[i] = 11;
                curr.push_back(temp);
                permute(nums, n, curr, S);
                curr.pop_back();
                nums[i] = temp;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> S;
        vector<int> curr;
        int n = nums.size();
        permute(nums, n, curr, S);
        vector<vector<int>> res(S.begin(), S.end());
        return res;
    }
};
// @lc code=end
