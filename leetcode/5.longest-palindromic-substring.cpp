/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLength(string s, int n, int l, int r)
    {
        int i = 0;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
                i++;
            }
            else
            {
                break;
            }
        }
        return i;
    }

    string makeMethod(string s)
    {
        int n = s.size();
        if (n == 1)
            return s;
        int _length = 1;
        int ans = 0;
        bool odd = true;
        for (int i = 0; i < n; i++)
        {
            int l = findLength(s, n, i - 1, i + 1);
            if (2 * l + 1 > _length)
            {
                ans = i;
                _length = 2 * l + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int l = findLength(s, n, i - 1, i);
            if (2 * l > _length)
            {
                ans = i;
                _length = 2 * l;
                odd = false;
            }
        }
        return s.substr(ans - _length / 2, _length);
    }

    string longestPalindrome(string s)
    {
        // Using Tabulation
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i > j)
                {
                    continue;
                }
                if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (j - i == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }

        int _max = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j - i + 1 > _max && dp[i][j])
                {
                    _max = j - i + 1;
                    res = i;
                }
            }
        }

        return s.substr(res, _max);
    }
};
// @lc code=end
