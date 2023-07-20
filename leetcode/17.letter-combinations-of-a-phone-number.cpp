/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void recursion(string digits, unordered_map<int, vector<char>> &letters, vector<string> &res, string s, int n, int i)
    {
        if (i == n)
        {
            res.push_back(s);
            return;
        }

        int digit = digits[i] - '0';

        for (char c : letters[digit])
        {
            recursion(digits, letters, res, s + c, n, i + 1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return {};
        }
        unordered_map<int, vector<char>> letters;
        letters[2] = {'a', 'b', 'c'};
        letters[3] = {'d', 'e', 'f'};
        letters[4] = {'g', 'h', 'i'};
        letters[5] = {'j', 'k', 'l'};
        letters[6] = {'m', 'n', 'o'};
        letters[7] = {'p', 'q', 'r', 's'};
        letters[8] = {'t', 'u', 'v'};
        letters[9] = {'w', 'x', 'y', 'z'};

        vector<string> res;
        recursion(digits, letters, res, "", digits.size(), 0);
        return res;
    }
};
// @lc code=end
