#include <bits/stdc++.h>
using namespace std;

int findPosition(int N)
{
    if (__builtin_popcount(N) != 1)
    {
        return -1;
    }

    for (int i = 0; i < 32; i++)
    {
        if (N >> i & 1)
        {
            return i + 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    cout << findPosition(n) << endl;
}