#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int &n, vector<int> &a, vector<int> &b, vector<bool> &vis)
{
    vis[node] = true;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if ((a[node - 1] - a[i - 1]) >= (b[node - 1] - b[i - 1]))
        {
            res += dfs(i, n, a, b, vis);
        }
    }

    return 1 + res;
}

pair<int, vector<int>> solve(vector<int> &a, vector<int> &b, int n)
{
    int res = 0;
    vector<int> strong;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(n + 1, false);
        int count = dfs(i, n, a, b, vis);
        if (count == n)
        {
            strong.push_back(i);
            res++;
        }
    }

    return {res, strong};
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        auto res = solve(a, b, n);
        cout << res.first << endl;
        if (res.first == 0)
            continue;
        for (int r : res.second)
        {
            cout << r << " ";
        }
        cout << endl;
    }
}