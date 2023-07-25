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

ll solveSurvive(ll n, ll k, vector<ll> &a)
{

    ll ptr = 0;
    ll ptr2 = 0;
    ll maxi = a[n - 1];
    vector<ll> survive(maxi - n);
    for (ll i = 1; i <= maxi; i++)
    {
        if (a[ptr2] != i)
        {
            survive[ptr++] = i;
        }
        else
        {
            ptr2++;
        }
    }

    vector<ll> living(maxi);
    for (ll i = 0; i < maxi; i++)
    {
        living[i] = i + 1;
    }

    ll toFill = maxi + 1;

    vector<ll> temp(maxi);

    while (k--)
    {

        for (ll i = 0; i < maxi - n; i++)
        {
            temp[i] = living[survive[i] - 1];
        }

        for (ll i = maxi - n; i < maxi; i++)
        {
            temp[i] = toFill++;
        }
        living = temp;
    }

    return living[0];
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

        cout << solveSurvive(n, k, a) << endl;
    }
}