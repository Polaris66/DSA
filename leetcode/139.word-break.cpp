/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool recursion(string s, vector<string> &words)
    {
        if (s.size() == 0)
        {
            return true;
        }
        bool res = false;
        for (string word : words)
        {
            if (s.size() >= word.size())
            {
                if (s.substr(0, word.size()) == word)
                {
                    res = res || recursion(s.substr(word.size(), s.size() - word.size()), words);
                }
            }
        }
        return res;
    }

    bool index(string s, int idx, vector<string> &words)
    {
        if (s.size() == idx)
        {
            return true;
        }

        bool res = false;
        for (string word : words)
        {
            if (s.size() >= word.size())
            {
                bool canTake = true;
                for (int i = 0; i < word.size(); i++)
                {
                    if (s[idx + i] != word[i])
                    {
                        canTake = false;
                        break;
                    }
                }

                if (canTake)
                {
                    res = res || index(s, idx + word.size(), words);
                }
            }
        }
        return res;
    }

    bool memoization(string s, int idx, vector<string> &words, vector<int> &memo)
    {
        if (s.size() == idx)
        {
            return true;
        }

        if (memo[idx] != -1)
        {
            return memo[idx];
        }

        bool res = false;
        for (string word : words)
        {
            if (s.size() >= word.size())
            {
                bool canTake = true;
                for (int i = 0; i < word.size(); i++)
                {
                    if (s[idx + i] != word[i])
                    {
                        canTake = false;
                        break;
                    }
                }

                if (canTake)
                {
                    res = res || memoization(s, idx + word.size(), words, memo);
                }
            }
        }
        return memo[idx] = res;
    }

    static bool compare(string a, string b)
    {
        return a.size() > b.size();
    }

    bool wordBreak(string s, vector<string> &words)
    {
        sort(words.begin(), words.end(), compare);

        vector<int> memo(s.size(), -1);
        return memoization(s, 0, words, memo);
    }
};
// @lc code=end
