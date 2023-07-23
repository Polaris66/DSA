#include <bits/stdc++.h>
using namespace std;

pair<int, int> fibonacci(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 2; i < n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }

    return make_pair(a, b);
}

int solve(int n, int k)
{
    // Formula => n = f(k-1) * x + f(k) * y -> find x & y
    // n = a*x + b*y

    pair<int, int> fib = fibonacci(k);
    int a = fib.first;
    int b = fib.second;

    int res = 0;
    for (int x = 0; a * x < n + 1; x++)
    {
        int sub = n - (a * x);
        if ((sub % b == 0) && (x <= (sub / b)))
        {
            res++;
        }
    }

    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        cout << solve(n, k) << endl;
    }
}
