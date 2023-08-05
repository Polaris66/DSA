#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &a)
{
    int prevLowest = a[0];
    int maxi = 0;
    for (int i = 1; i < a.size(); i++)
    {
        maxi = max(maxi, a[i] - prevLowest);
        prevLowest = min(prevLowest, a[i]);
    }
    return maxi;
}