#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

bool solve(int n, vector<ll> &a)
{
    ll sum = n * (n + 1) / 2;

    int size = n - 1;

    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] > sum)
        {
            return false;
        }
    }

    vector<ll> diff(size);
    diff[0] = a[0];

    for (int i = 1; i < size; i++)
    {
        diff[i] = a[i] - a[i - 1];
    }

    sort(diff.begin(), diff.end());

    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    vector<ll> leftA;
    vector<ll> leftB;

    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr1 < n - 1 && ptr2 < n)
    {
        if (diff[ptr1] == nums[ptr2])
        {
            ptr1++;
            ptr2++;
        }
        else if (diff[ptr1] > nums[ptr2])
        {
            leftB.push_back(nums[ptr2]);
            if (leftB.size() > 2)
            {
                return false;
            }
            ptr2++;
        }
        else
        {
            leftA.push_back(diff[ptr1]);
            if (leftA.size() > 1)
            {
                return false;
            }
            ptr1++;
        }
    }

    while (ptr1 < n - 1)
    {
        leftA.push_back(diff[ptr1++]);
    }

    while (ptr2 < n)
    {
        leftB.push_back(nums[ptr2++]);
    }

    if (leftB.size() == 2 && leftA.size() == 1)
    {
        return (leftB[0] + leftB[1]) == leftA[0];
    }

    if (leftB.size() == 1 && leftA.size() == 0)
    {
        return true;
    }

    return false;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n - 1);
        for (auto &x : a)
        {
            cin >> x;
        }

        if (solve(n, a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}