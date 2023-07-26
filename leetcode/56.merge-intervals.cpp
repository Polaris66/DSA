/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        map<int, int> mp;
        for (vector<int> i : intervals)
        {
            mp[i[0]] += 1;
            mp[i[1]] += -1;
        }

        vector<vector<int>> res;
        int start = -1;
        int cnt = 0;
        for (auto it : mp)
        {
            if (start == -1)
            {
                start = it.first;
            }
            cnt += it.second;

            if (cnt == 0)
            {
                res.push_back({start, it.first});
                start = -1;
            }
        }
        return res;
    }
};
// @lc code=end
