#include <bits/stdc++.h>
using namespace std;
bool solve(int n, int k, vector<int> &a)
{
    if (k == 1)
        return true;

    if (a[0] == a[n - 1])
    {
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[0])
            {
                c++;
            }
        }
        if (c >= k)
        {
            return true;
        }
    }

    int l = 0;
    int c = 0;
    while (l < n && c < k)
    {
        if (a[l++] == a[0])
        {
            c++;
        }
    }

    if (c != k)
        return false;

    int r = n - 1;
    c = 0;
    while (r >= l && c < k)
    {
        if (a[r--] == a[n - 1])
        {
            c++;
        }
    }

    if (c != k)
    {
        return false;
    }

    return true;
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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (solve(n, k, a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}