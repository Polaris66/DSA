#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n, ll k, vector<ll> &a)
{
    ll size = a[n - 1];
    ll maxi = 0;
    queue<ll> Q;

    // Loop
    while (k--)
    {
        ll current_size = Q.size();
        for (ll i = 0; i < (size - current_size); i++)
        {
            maxi++;
            Q.push(maxi);
        }

        ll ptr = 0;
        for (ll i = 0; i < size; i++)
        {
            if (ptr == n)
            {
                break;
            }
            if ((i + 1) == a[ptr])
            {
                Q.pop();
                ptr++;
            }
            else
            {
                ll val = Q.front();
                Q.pop();
                Q.push(val);
            }
        }
    }
    return Q.front();
}

ll solveVec(ll n, ll k, vector<ll> &a)
{
    ll maxi = a[n - 1];
    vector<ll> V(maxi * k);
    for (ll i = 0; i < (maxi * k); i++)
    {
        V[i] = (i + 1);
    }
    while (k--)
    {
        for (ll i = n - 1; i > -1; i--)
        {
            V.erase(V.begin() + a[i] - 1);
        }
    }

    return V[0];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (auto &x : a)
        {
            cin >> x;
        }

        cout << solve(n, k, a) << endl;
    }
}