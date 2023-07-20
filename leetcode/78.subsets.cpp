/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void recursion(vector<int> &a, int i, vector<int> curr, set<vector<int>> &res)
    {
        if (i == a.size())
        {
            res.insert(curr);
            return;
        }

        if (res.find(curr) != res.end())
        {
            return;
        }
        recursion(a, i + 1, curr, res);
        curr.push_back(a[i]);
        recursion(a, i + 1, curr, res);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        set<vector<int>> S;
        recursion(nums, 0, vector<int>(), S);
        for (vector<int> x : S)
        {
            res.push_back(x);
        }
        return res;
    }
};
// @lc code=end
