/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int recursion(string s, int i)
    {
        if (i < 0)
        {
            return 1;
        }

        int res = 0;
        if ((s[i] <= '9') && (s[i] >= '1'))
        {
            res += recursion(s, i - 1);
        }
        if ((i > 0) && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26)
        {
            res += recursion(s, i - 2);
        }

        return res;
    }

    int memoization(string s, int i, vector<int> &memo)
    {
        if (i < 0)
        {
            return 1;
        }

        if (memo[i] != -1)
        {
            return memo[i];
        }

        int res = 0;
        if ((s[i] <= '9') && (s[i] >= '1'))
        {
            res += memoization(s, i - 1, memo);
        }
        if ((i > 0) && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26)
        {
            res += memoization(s, i - 2, memo);
        }

        return memo[i] = res;
    }
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> memo(n, -1);
        return memoization(s, n - 1, memo);
    }
};
// @lc code=end
