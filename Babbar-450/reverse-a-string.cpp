#include <bits/stdc++.h>
using namespace std;

string reverseWord(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << reverseWord(s) << endl;
}