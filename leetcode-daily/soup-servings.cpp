#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int, double>> dp;
double recursion(int A, int B)
{
    if (A <= 0 && B <= 0)
    {
        return 0.5;
    }
    if (A <= 0)
    {
        return 1;
    }
    if (B <= 0)
    {
        return 0;
    }

    if (dp[A].count(B))
    {
        return dp[A][B];
    }

    double p = recursion(A - 4, B) + recursion(A - 3, B - 1) + recursion(A - 2, B - 2) + recursion(A - 1, B - 3);
    return dp[A][B] = p * 0.25;
}
double soupServings(int n)
{
    int m = ceil((double)n / 25.0);

    // Assume it goes to 1 sometimes, instead of solving for all, solve only for (1,1) to (k,k)

    for (int k = 0; k <= m; k++)
    {
        double val = recursion(k, k);
        if (val >= 1 - 1e-5)
        {
            return 1;
        }
    }

    return recursion(m, m);
}

int main()
{
    int n;
    cin >> n;

    cout << soupServings(n) << endl;
}