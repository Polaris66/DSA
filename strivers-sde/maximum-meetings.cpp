#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        m.push_back(make_pair(end[i], start[i]));
    }

    sort(m.begin(), m.end());

    int taken = m[0].first;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (m[i].second > taken)
        {
            res++;
            taken = m[i].first;
        }
    }

    return res;
}