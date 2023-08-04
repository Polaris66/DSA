#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll square(ll n)
{
    n = abs(n);
    ll temp = 0;
    ll res = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((temp + (1LL << i)) <= n)
        {
            temp += (1LL << i);
            res += (n << i);
        }
    }

    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << square(n) << endl;
}