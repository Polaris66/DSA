#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(a[i].begin(), a[i].end());
    }
}