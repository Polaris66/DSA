#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k, int H, vector<int> &h)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = abs(H - h[i]);
        if ((diff % k) == 0)
        {
            if (((diff / k) >= 1) && ((diff / k) <= m - 1))
            {
                res++;
            }
        }
    }

    return res;
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
        int n, m, k, H;
        cin >> n >> m >> k >> H;

        vector<int> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        cout << solve(n, m, k, H, h) << endl;
    }
}