#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int> &a, int n, vector<vector<ll>> &Q, int q)
{
    unordered_map<ll, int> mp;
    ll m = 1e10;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll x = a[i], y = a[j];
            mp[(x * y) * m + x + y]++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << mp[Q[i][1] * m + Q[i][0]] << " ";
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
        }

        int q;
        cin >> q;

        vector<vector<ll>> Q(q);

        for (int i = 0; i < q; i++)
        {
            ll x, y;
            cin >> x >> y;
            Q[i].push_back(x);
            Q[i].push_back(y);
        }

        solve(a, n, Q, q);
        cout << endl;
    }
}