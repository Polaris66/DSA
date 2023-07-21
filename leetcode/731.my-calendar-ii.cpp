/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyCalendarTwo
{
public:
    map<int, int> m;
    MyCalendarTwo()
    {
    }

    bool canAdd()
    {
        int c = 0;
        for (auto it : m)
        {
            c += it.second;
            if (c > 2)
            {
                return false;
            }
        }

        return true;
    }

    bool book(int start, int end)
    {
        m[start]++;
        m[end]--;
        if (canAdd())
        {
            return true;
        }
        m[start]--;
        m[end]++;
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
