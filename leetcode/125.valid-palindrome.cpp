/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string new_s = "";
        for (char c : s)
        {
            if (c == ' ')
            {
                continue;
            }
            if (((c <= 'z') && (c >= 'a')) || ((c <= '9') && (c >= '0')))
            {
                new_s += c;
            }
            else if ((c <= 'Z') && (c >= 'A'))
            {
                new_s += (c - 'A' + 'a');
            }
        }

        string reversed = new_s;
        reverse(reversed.begin(), reversed.end());
        return reversed == new_s;
    }
};
// @lc code=end
