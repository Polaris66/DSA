#include <bits/stdc++.h>
using namespace std;

int setBits(int N)
{
    int cnt = 0;
    for (int i = 0; i <= 31; i++)
    {
        cnt += ((N & 1 << i) != 0);
    }
    return cnt;
}

int builtin(int n)
{
    return __builtin_popcount(n);
}

int main()
{
    int n;
    cin >> n;
    cout << setBits(n) << endl;
}