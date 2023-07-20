/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        string word = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += s[i];
            }
        }
        if (word != "")
        {
            words.push_back(word);
        }

        if (pattern.size() != words.size())
        {
            return false;
        }
        unordered_map<char, string> mp;
        unordered_map<string, char> reverse;

        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.count(pattern[i]) || reverse.count(words[i]))
            {
                if (mp[pattern[i]] != words[i] || reverse[words[i]] != pattern[i])
                {
                    return false;
                }
            }
            else
            {
                mp[pattern[i]] = words[i];
                reverse[words[i]] = pattern[i];
            }
        }

        return true;
    }
};
// @lc code=end
