#include <bits/stdc++.h>
using namespace std;

long long divide(long long a, long long b)
{
    int sign = (a < 0) ^ (b < 0) ? -1 : 1;

    a = abs(a);
    b = abs(b);

    long long res = 0;
    long long curr = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (curr + (b << i) <= a)
        {
            curr += (b << i);
            res += 1 << i;
        }
    }
    if (sign == -1)
    {
        return -res;
    }
    return res;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << divide(a, b) << endl;
}
