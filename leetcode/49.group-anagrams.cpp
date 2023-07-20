/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (string s : strs)
        {
            string sorted_string = s;
            sort(sorted_string.begin(), sorted_string.end());
            mp[sorted_string].push_back(s);
        }

        vector<vector<string>> res;

        for (auto it : mp)
        {
            res.push_back(it.second);
        }

        return res;
    }
};
// @lc code=end
