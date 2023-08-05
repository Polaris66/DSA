#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll recursion(vector<int> &a, int unlocked, int idx, vector<vector<ll>> &memo)
{
    if (idx == (int)a.size() || idx > (unlocked))
    {
        return 0;
    }

    if (unlocked >= a.size())
    {
        unlocked = (int)a.size() - 1;
    }

    if (memo[unlocked][idx] != -1)
    {
        return memo[unlocked][idx];
    }

    ll res = recursion(a, unlocked + a[idx], idx + 1, memo);
    res = max(res, a[idx] + recursion(a, unlocked, idx + 1, memo));

    return memo[unlocked][idx] = res;
}

int tabulation(vector<int> &a, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int unlocked = n - 1; unlocked >= 0; unlocked--)
        {
            if (unlocked >= idx)
            {
                int take = a[idx] + dp[unlocked][min(n - 1, idx + 1)];
                int open = dp[min(n - 1, unlocked + a[idx])][min(n - 1, idx + 1)];
                dp[unlocked][idx] = max(take, open);
            }
        }
    }

    return dp[0][0];
}

int optimisation(vector<int> &a, int n)
{
    vector<int> curr(n, 0);
    vector<int> prev(n, 0);

    prev[n - 1] = a[n - 1];

    for (int idx = n - 2; idx >= 0; idx--)
    {
        for (int unlocked = n - 1; unlocked >= 0; unlocked--)
        {
            if (unlocked >= idx)
            {
                int take = a[idx] + prev[unlocked];
                int open = prev[min(n - 1, unlocked + a[idx])];
                curr[unlocked] = max(take, open);
            }
        }

        prev = curr;
    }

    return prev[0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    // vector<vector<ll>> memo(n, vector<ll>(n, -1));
    // cout << recursion(a, 0, 0, memo)<<endl;

    // cout << tabulation(a, n) << endl;
    cout << optimisation(a, n) << endl;
}