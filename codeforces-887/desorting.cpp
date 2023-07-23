#include <bits/stdc++.h>
using namespace std;

int desorting(vector<int> &a, int n)
{
    // Check for base case
    bool unsorted = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            unsorted = true;
            break;
        }
    }

    if (unsorted)
    {
        return 0;
    }

    int mini_index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i + 1] - a[i]) < (a[mini_index + 1] - a[mini_index]))
        {
            mini_index = i;
        }
    }

    int diff = a[mini_index + 1] - a[mini_index] + 1;

    return diff % 2 == 0 ? diff / 2 : diff / 2 + 1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
        }

        cout << desorting(a, n) << endl;
    }
}