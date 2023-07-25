/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // O(m+n)
    double Merge(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int i = 0;
        int j = 0;
        int m = nums1.size();
        int n = nums2.size();
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else
            {
                res.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m)
        {
            res.push_back(nums1[i]);
            i++;
        }

        while (j < n)
        {
            res.push_back(nums2[j]);
            j++;
        }

        cout << res[(m + n) / 2 - 1] << endl;
        cout << res[(m + n) / 2] << endl;
        return (m + n) % 2 == 0 ? ((double)res[(m + n) / 2 - 1] + (double)res[(m + n) / 2]) / 2 : res[((m + n) / 2)];
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while (low <= high)
        {
            int cut1 = low + (high - low) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(left1, left2) + min(right1, right2)) / 2.00;
                }
                else
                {
                    return max(left1, left2);
                }
            }
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};
// @lc code=end
