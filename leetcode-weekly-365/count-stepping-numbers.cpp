#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

ll dp[101][2][2][11];

ll recursion(string &s, ll idx, ll tight, ll isZero, ll prevDigit)
{
    if (idx == s.size())
    {
        if (isZero)
        {
            return 0;
        }
        return 1;
    }

    if (dp[idx][tight][isZero][prevDigit + 1] != -1)
    {
        return dp[idx][tight][isZero][prevDigit + 1];
    }

    ll res = 0;

    int limit = tight ? s[idx] - '0' : 9;
    for (int digit = 0; digit <= limit; digit++)
    {
        ll newTight = tight;
        if (tight && digit < limit)
            newTight = 0;

        ll newZero = isZero;
        if (isZero && digit != 0)
            newZero = 0;

        if (isZero)
        {
            res += recursion(s, idx + 1, newTight, newZero, digit);
            res %= MOD;
        }
        else
        {
            if (abs(digit - prevDigit) == 1)
            {
                res += recursion(s, idx + 1, newTight, newZero, digit);
                res %= MOD;
            }
        }
    }
    res %= MOD;
    dp[idx][tight][isZero][prevDigit + 1] = res;
    return res;
}

int countSteppingNumbers(string low, string high)
{
    ll res = 0;
    memset(dp, -1, sizeof(dp));
    res += recursion(high, 0, 1, 1, -1);
    res %= MOD;
    memset(dp, -1, sizeof(dp));
    res -= recursion(low, 0, 1, 1, -1);
    res %= MOD;
    res += MOD;
    res %= MOD;

    bool add = true;
    for (int i = 0; i < low.size() - 1; i++)
    {
        if (abs(low[i] - low[i + 1]) != 1)
        {
            add = false;
        }
    }
    if (add)
    {
        res++;
    }
    res %= MOD;
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << countSteppingNumbers(a, b) << endl;
}
