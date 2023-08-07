#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int> &a, int n)
{
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    unordered_map<int, int> mp;
    ll sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= temp[i];
        mp[temp[i]] = ((-n + 2 * i + 1) * temp[i]) - sum2 + sum + n;
        sum2 += temp[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << mp[a[i]] << " ";
    }
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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
        cout << endl;
    }
}
