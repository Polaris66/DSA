/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool condition(unordered_map<char, int> &window, unordered_map<char, int> &temp)
    {
        for (auto it : temp)
        {
            if (window[it.first] < it.second)
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        int n = s.size();
        int i = 0;
        int j = 0;
        int x = -1;
        int min_len = INT_MAX;
        unordered_map<char, int> temp;
        for (char c : t)
        {
            temp[c]++;
        }
        unordered_map<char, int> window;
        while (j < n)
        {
            if (temp.count(s[j]))
            {
                window[s[j]]++;
            }
            while (condition(window, temp))
            {
                if (j - i + 1 < min_len)
                {
                    min_len = j - i + 1;
                    x = i;
                }
                window[s[i]]--;
                i++;
            }
            j++;
        }
        if (min_len != INT_MAX)
        {
            return s.substr(x, min_len);
        }
        return "";
    }
};
// @lc code=end
