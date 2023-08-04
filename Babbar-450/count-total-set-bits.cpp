#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    if (n == 0)
        return 0;
    int x = 0;
    while ((n) >= (1 << x))
    {
        x++;
    }
    x--;

    int res = 0;
    res += (1 << (x - 1)) * x;

    res += (n - (1 << x) + 1);

    res += countSetBits(n - (1 << x));
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << countSetBits(n);
}