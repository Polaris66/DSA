/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0)
            return false;

        // Assume First Jump Done
        int n = nums.size();
        int maxReachable = nums[0];
        int stepsLeft = nums[0];
        int i = 1;
        while (i < n)
        {
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxReachable >= n - 1)
            {
                return true;
            }
            stepsLeft--;

            if (stepsLeft == 0)
            {
                stepsLeft = maxReachable - i;
                if (stepsLeft == 0)
                {
                    return false;
                }
            }

            i++;
        }

        return true;
    }
};
// @lc code=end
