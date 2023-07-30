#include <bits/stdc++.h>
using namespace std;

string minString(string a, string b)
{
    if (a.size() < b.size())
    {
        return a;
    }
    if (a.size() == b.size())
    {
        if (a < b)
        {
            return a;
        }
    }
    return b;
}

string merge(string a, string b)
{
    if (a.find(b) != string::npos)
    {
        return a;
    }

    for (int i = 0; i < a.size(); i++)
    {
        string t1 = a.substr(i);
        string t2 = b.substr(0, t1.size());
        if (t1 == t2)
        {
            return a + b.substr(t1.size());
        }
    }
    return a + b;
}

string solve(string &a, string &b, string &c)
{
    return merge(merge(a, b), c);
}

string minimumString(string a, string b, string c)
{
    string res = solve(a, b, c);
    res = minString(res, solve(a, c, b));
    res = minString(res, solve(b, a, c));
    res = minString(res, solve(b, c, a));
    res = minString(res, solve(c, a, b));
    res = minString(res, solve(c, b, a));
    return res;
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    cout << minimumString(a, b, c);
}