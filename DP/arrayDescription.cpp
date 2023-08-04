#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

// Arrays that can be made with putting x at i
ll recursion(vector<int> &a, int m, int i, int x, vector<vector<ll>> &memo)
{
    if (x > m)
        return 0;
    if (x < 1)
        return 0;

    if (i == 0)
    {
        if ((a[i] == 0) || (x == a[i]))
        {
            return 1;
        }
    }

    if (a[i] != 0 && a[i] != x)
    {
        return 0;
    }

    if (memo[x][i] != -1)
    {
        return memo[x][i];
    }

    ll ways = 0;
    ways += recursion(a, m, i - 1, x + 1, memo) % mod;
    ways += recursion(a, m, i - 1, x - 1, memo) % mod;
    ways += recursion(a, m, i - 1, x, memo) % mod;
    return memo[x][i] = ways % mod;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (auto &x : nums)
    {
        cin >> x;
    }

    vector<vector<ll>> memo(m + 1, vector<ll>(n + 1, -1));
    ll res = 0;
    for (int i = 1; i <= m; i++)
    {
        res += recursion(nums, m, n - 1, i, memo) % mod;
    }
    cout << res % mod << endl;
}