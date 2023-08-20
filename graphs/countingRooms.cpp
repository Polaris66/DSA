#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &a, int &m, int &n, int &i, int &j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
    {
        return false;
    }
    if (a[i][j] == '#')
    {
        return false;
    }

    return true;
}

void dfs(vector<vector<char>> &a, int &m, int &n, vector<vector<bool>> &Vis, vector<pair<int, int>> &Dir, int i, int j)
{
    Vis[i][j] = true;
    for (int idx = 0; idx < 4; idx++)
    {
        int new_i = i + Dir[idx].first;
        int new_j = j + Dir[idx].second;

        if (isValid(a, m, n, new_i, new_j) && !Vis[new_i][new_j])
        {
            dfs(a, m, n, Vis, Dir, new_i, new_j);
        }
    }
}

int solve(vector<vector<char>> &a, int &m, int &n)
{
    vector<pair<int, int>> Dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> Vis(m, vector<bool>(n, false));

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isValid(a, m, n, i, j) && !Vis[i][j])
            {
                dfs(a, m, n, Vis, Dir, i, j);
                res++;
            }
        }
    }

    return res;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<char>> a(m, vector<char>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << solve(a, m, n) << endl;
}