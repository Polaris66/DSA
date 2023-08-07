#include <bits/stdc++.h>
using namespace std;

string solve(string &s)
{
    int n = s.size();
    bool carry = false;
    int lastCarried = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (carry)
        {
            if (s[i] != '9')
            {
                s[i]++;
                carry = false;
            }
            else
            {
                s[i] = '0';
            }
        }

        if ((s[i] - '0') < 5)
        {
            continue;
        }
        else
        {
            carry = true;
            lastCarried = i;
        }
    }

    for (int i = lastCarried; i < n; i++)
    {
        s[i] = '0';
    }

    if (carry)
    {
        s = '1' + s;
    }
    return s;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}