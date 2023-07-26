#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

void solve(int n, int k, vector<ll> m, ll &a, ll &b, ll &x)
{
    ll res = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll val = m[i] ^ m[j];
            if (val < res)
            {
                res = val;
                a = i;
                b = j;
            }
        }
    }

    x = (((1 >> k - 1) & ~res));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ll> m(n);
        for (int i = 0; i < n; i++)
        {
            cin >> m[i];
        }

        ll a, b, x;
        solve(n, k, m, a, b, x);
        cout << a + 1 << " " << b + 1 << " " << x << endl;
    }
}