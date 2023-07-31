#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];
int recursion(string &s1, string &s2, int i, int j)
{
    int m = s1.size();
    int n = s2.size();
    if (i == m && j == n)
    {
        return 0;
    }
    if (i == m)
    {
        int res = 0;
        for (int idx = j; idx < n; idx++)
        {
            res += (int)s2[idx];
        }
        return res;
    }
    if (j == n)
    {
        int res = 0;
        for (int idx = i; idx < m; idx++)
        {
            res += (int)s1[idx];
        }
        return res;
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    if (s1[i] == s2[j])
    {
        return recursion(s1, s2, i + 1, j + 1);
    }

    int delete1 = (int)s1[i] + recursion(s1, s2, i + 1, j);
    int delete2 = (int)s2[j] + recursion(s1, s2, i, j + 1);

    memo[i][j] = min(delete1, delete2);
    return memo[i][j];
}

int minimumDeleteSum(string s1, string s2)
{
    memset(memo, -1, sizeof(memo));
    return recursion(s1, s2, 0, 0);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minimumDeleteSum(s1, s2) << endl;
}