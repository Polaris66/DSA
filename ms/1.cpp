#include <bits/stdc++.h>
using namespace std;

string remove_duplicates(string s)
{
    sort(s.begin(), s.end());

    int n = s.size();
    string res = "";
    res += s[0];
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[i - 1])
        {
            while (s[i] == s[i - 1])
            {
                i++;
            }
        }

        else
        {
            res += s[i];
            i++;
        }
    }
    return res;
}

void comb(vector<char> &opt, string &curr, int K, vector<string> &res)
{
    if (curr.size() == K)
    {
        res.push_back(curr);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (opt[i] != '.')
        {
            char c = opt[i];
            curr += c;
            opt[i] = '.';
            comb(opt, curr, K, res);
            opt[i] = c;
            curr.pop_back();
        }
    }
}

bool check(string a, string b)
{
    int m = a.size();
    int n = b.size();
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            return false;
        }
        else
        {
            j++;
        }
    }

    return (i == m);
}

int solution(vector<string> &S, int K)
{
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
        S[i] = remove_duplicates(S[i]);
    }

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (S[i].size() <= K)
        {
            mp[S[i]]++;
        }
    }

    vector<string> com;
    vector<char> opt = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    string curr = "";
    comb(opt, curr, K, com);

    int maxi = 0;
    for (auto c : com)
    {
        int res = 0;
        for (auto s : mp)
        {
            if (check(s.first, c))
            {
                res += s.second;
            }
        }
        maxi = max(maxi, res);
    }

    return maxi;
}

int main()
{
    int n;
    cin >> n;

    vector<string> S(n);
    for (auto &s : S)
    {
        cin >> s;
    }

    int K;
    cin >> K;
    cout << solution(S, K) << endl;
}