#include <bits/stdc++.h>
using namespace std;

int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
{
    int res = 0;
    for (int h : hours)
    {
        if (h >= target)
        {
            res++;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
}