#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> &Adj, int x, vector<int> &memo)
{
    if (memo[x] != -1)
    {
        return memo[x];
    }

    int res = 0;
    for (int i : Adj[x])
    {
        res += 1 + recursion(Adj, i, memo);
    }

    return memo[x] = res;
}

vector<int> solve(int &n, vector<int> hei)
{
    vector<vector<int>> Adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        Adj[hei[i]].push_back(i + 1);
    }

    vector<int> memo(n, -1);
    for (int i = 0; i < n; i++)
    {
        recursion(Adj, i, memo);
    }

    return memo;
}

int main()
{
    int n;
    cin >> n;

    vector<int> hei(n - 1);
    for (auto &x : hei)
    {
        cin >> x;
        x--;
    }

    vector<int> res = solve(n, hei);

    for (int i : res)
    {
        cout << i << ' ';
    }
}