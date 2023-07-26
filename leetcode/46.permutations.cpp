/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void permute(vector<int> &nums, int n, vector<int> &curr, vector<vector<int>> &res)
    {
        if (curr.size() == n)
        {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != -11)
            {
                int temp = nums[i];
                nums[i] = -11;
                curr.push_back(temp);
                permute(nums, n, curr, res);
                curr.pop_back();
                nums[i] = temp;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        permute(nums, nums.size(), curr, res);
        return res;
    }
};
// @lc code=end
