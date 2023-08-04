#include <bits/stdc++.h>
using namespace std;

int setSetBit(int x, int y, int l, int r)
{
    for (int i = l - 1; i <= r - 1; i++)
    {
        if (y >> i & 1)
        {
            x = x | (1 << i);
        }
    }
    return x;
}

int main()
{
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    cout << setSetBit(x, y, l, r);
}