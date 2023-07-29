#include <bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n)
{
    return (__builtin_popcountll(n) == 1);
}

int main()
{
    long long n;
    cin >> n;
    cout << isPowerofTwo(n) << endl;
}