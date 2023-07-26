#include <bits/stdc++.h>
using namespace std;
int solve(int i, vector<vector<int>> &M, vector<int> &C, vector<bool> &O, vector<int> &memo)
{
    if (O[i])
    {
        return 0;
    }

    if (memo[i] != -1)
    {
        return memo[i];
    }

    int res = C[i];
    if (M[i].size() != 0)
    {
        int mix = 0;
        for (int x : M[i])
        {
            mix += solve(x - 1, M, C, O, memo);
        }
        res = min(res, mix);
    }
    return memo[i] = res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> C(n);
        for (int i = 0; i < n; i++)
        {
            cin >> C[i];
        }

        vector<bool> O(n);
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            O[x - 1] = true;
        }

        vector<vector<int>> M(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;

            while (m--)
            {
                int x;
                cin >> x;
                M[i].push_back(x);
            }
        }

        vector<int> memo(n, -1);
        for (int i = 0; i < n; i++)
        {
            cout << solve(i, M, C, O, memo) << " ";
        }
        cout << endl;
    }
}