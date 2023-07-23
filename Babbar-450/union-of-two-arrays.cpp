#include <bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        mp[b[i]]++;
    }

    return mp.size();
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    cout << doUnion(a, n, b, m) << endl;
}