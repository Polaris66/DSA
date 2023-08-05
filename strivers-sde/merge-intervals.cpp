#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &a)
{
    sort(a.begin(), a.end());

    vector<vector<int>> res;
    for (vector<int> inte : a)
    {
        if (res.empty() || inte[0] > res.back()[1])
        {
            res.push_back(inte);
        }
        else
        {
            res.back()[1] = max(res.back()[1], inte[1]);
        }
    }

    return res;
}