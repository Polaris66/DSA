/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                if (nums[mid] <= nums[r])
                {
                    r = mid - 1;
                }
                else
                {
                    if (nums[r] == target)
                        return r;
                    if (nums[r] < target)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
            else
            {
                if (nums[mid] >= nums[l])
                {
                    l = mid + 1;
                }
                else
                {
                    if (nums[l] == target)
                    {
                        return l;
                    }
                    if (nums[l] < target)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
        }

        return -1;
    }
};
// @lc code=end
