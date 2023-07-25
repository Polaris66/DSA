#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[slow];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << findDuplicate(nums) << endl;
}