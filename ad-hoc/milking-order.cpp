#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> hei(m);
    for (auto &x : hei)
    {
        cin >> x;
    }

    vector<int> fixed(n + 1, 0);
    vector<int> arr(n + 1, 0);

    for (int i = 0; i < k; i++)
    {
        int c, p;
        cin >> c >> p;
        fixed[c] = p;
        arr[p] = c;
    }

    if (fixed[1])
    {
        cout << fixed[1] << '\n';
        return 0;
    }

    int ptr = n;
    for (int i = m - 1; i >= 0; i--)
    {
        int cur = hei[i];
        if (cur == 1)
        {
            ptr = 1;
            for (int j = 0; j <= i; j++)
            {
                cur = hei[j];
                if (fixed[cur])
                {
                    ptr = fixed[cur] + 1;
                    continue;
                }

                while (arr[ptr])
                {
                    ptr++;
                }
                arr[ptr] = cur;
                ptr++;
            }

            cout << ptr - 1 << '\n';
            return 0;
        }

        if (fixed[cur])
        {
            ptr = fixed[cur] - 1;
            continue;
        }

        while (arr[ptr])
        {
            ptr--;
        }
        arr[ptr] = cur;
        ptr--;
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            cout << i << '\n';
            return 0;
        }
    }
}