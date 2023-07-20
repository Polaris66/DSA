/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void recursion(vector<int> &c, int i, int n, vector<int> combination, vector<vector<int>> &res)
    {
        if (n == 0)
        {
            res.push_back(combination);
            return;
        }

        if (n < 0)
        {
            return;
        }

        if ((i < 0) && (n > 0))
        {
            return;
        }

        recursion(c, i - 1, n, combination, res);
        combination.push_back(c[i]);
        recursion(c, i, n - c[i], combination, res);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        recursion(candidates, candidates.size() - 1, target, vector<int>(), res);
        return res;
    }
};
// @lc code=end
