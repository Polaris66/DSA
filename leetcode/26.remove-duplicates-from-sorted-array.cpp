/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int ptr1 = 1;
        int ptr2 = 1;
        while (ptr2 < n)
        {
            if (nums[ptr2] == nums[ptr2 - 1])
            {
                ptr2++;
            }
            else
            {
                nums[ptr1++] = nums[ptr2++];
            }
        }

        return ptr1;
    }
};
// @lc code=end
