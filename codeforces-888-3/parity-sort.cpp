#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int> a)
{
    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)
        {
            odd.push_back(a[i]);
        }
        else
        {
            even.push_back(a[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int ptr1 = 0;
    int ptr2 = 0;
    vector<int> test(n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)
        {
            test[i] = odd[ptr1++];
        }
        else
        {
            test[i] = even[ptr2++];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (test[i] > test[i + 1])
        {
            return false;
        }
    }

    return true;
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (solve(n, a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}