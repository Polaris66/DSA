#include <bits/stdc++.h>
using namespace std;

int solve(int &n, vector<string> &a)
{
    unordered_map<string, int> M;
    for (int i = 0; i < n; i++)
    {
        string s = a[i];
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        M[sorted]++;
    }

    int res = 0;
    for (auto it : M)
    {
        res += (it.second) * (it.second - 1) / 2;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    cout << solve(n, a) << endl;
}