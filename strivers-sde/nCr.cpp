#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r)
{
    if ((n - r) < r)
    {
        return nCr(n, n - r);
    }

    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{
    int n, r;
    cin >> n >> r;

    cout << nCr(n, r) << endl;
}