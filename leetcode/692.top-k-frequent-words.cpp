/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> ft;
        for (string s : words)
        {
            ft[s]++;
        }

        vector<pair<string, int>> a;
        for (auto it : ft)
        {
            a.push_back(make_pair(it.first, it.second));
        }

        sort(a.begin(), a.end(), cmp);
        vector<string> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(a[i].first);
        }

        return res;
    }
};
// @lc code=end
