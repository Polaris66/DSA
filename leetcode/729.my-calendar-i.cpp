/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyCalendar
{
public:
    map<int, int> m;
    MyCalendar()
    {
    }

    bool canAdd()
    {
        int c = 0;
        for (auto it : m)
        {
            c += it.second;
            if (c > 1)
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
