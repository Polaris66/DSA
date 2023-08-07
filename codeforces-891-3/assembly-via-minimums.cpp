#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> &a)
{
    int total = a.size();
    map<int, int> mp;
    for (int x : a)
    {
        mp[x]++;
    }

    vector<int> res;
    int take = n - 1;
    for (auto it : mp)
    {
        while (mp[it.first] > 0)
        {
            res.push_back(it.first);
            mp[it.first] -= take;
            take--;
        }
    }

    res.push_back(res.back());
    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a((n) * (n - 1) / 2);

        for (auto &x : a)
        {
            cin >> x;
        }

        vector<int> res = solve(n, a);

        for (int x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}