#include <bits/stdc++.h>
using namespace std;

int recursion(int x, vector<int> &h, vector<int> &s, int i)
{
    if (i < 0)
    {
        return 0;
    }

    int maxi = 0;
    int include = 0;
    if (x - h[i] > -1)
    {
        include = s[i] + recursion(x - h[i], h, s, i - 1);
    }
    maxi = max(include, maxi);

    int exclude = recursion(x, h, s, i - 1);
    maxi = max(exclude, maxi);

    return maxi;
}

int memoization(int x, vector<int> &h, vector<int> &s, int i, vector<vector<int>> &memo)
{
    if (i < 0)
    {
        return 0;
    }

    if (memo[i][x] != -1)
    {
        return memo[i][x];
    }

    int maxi = 0;
    int include = 0;
    if (x - h[i] > -1)
    {
        include = memoization(x - h[i], h, s, i - 1, memo) + s[i];
    }
    maxi = max(maxi, include);

    int exclude = memoization(x, h, s, i - 1, memo);
    maxi = max(maxi, exclude);

    memo[i][x] = maxi;
    return memo[i][x];
}

int tabulation(int x, vector<int> &h, vector<int> &s)
{
    int n = h.size();

    vector<int> curr(x + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j > -1; j--)
        {
            int include = 0;
            if (h[i] <= j)
            {
                include = s[i] + curr[j - h[i]];
            }

            int exclude = curr[j];
            curr[j] = max(exclude, include);
        }
    }

    return curr[x];
}

// Can be space optimised to use only 2 rows
int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> h(n);
    for (auto &element : h)
    {
        cin >> element;
    }

    vector<int> s(n);
    for (auto &element : s)
    {
        cin >> element;
    }

    // cout<<recursion(x,h,s,n-1)<<endl;

    // vector<vector<int>> memo(n, vector<int> (x+1,-1));
    // cout<<memoization(x,h,s,n-1,memo);

    cout << tabulation(x, h, s) << endl;
}