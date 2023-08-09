#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> order(m);
    for (auto &x : order)
    {
        cin >> x;
    }

    vector<int> next(n + 1, 0);
    for (int i = m - 1; i > 0; i--)
    {
        next[order[i]] = order[i + 1];
    }

    vector<int> pos(n + 1, 0);

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        pos[y] = x;
    }

    int carried = 0;
    for (int i = n; i > 0; i--)
    {
        if (pos[i] != 0)
        {
            if (next[pos[i]] != 0)
            {
                carried = next[pos[i]];
            }
        }
        else
        {
            if (carried)
            {
                pos[i] = carried;
                carried = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (pos[i] == 0)
        {
            cout << i << endl;
            break;
        }
    }
}