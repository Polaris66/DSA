#include <bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n)
{
    int arr[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;
    vector<int> res;
    while (n)
    {
        if (n >= arr[i])
        {
            res.push_back(arr[i]);
            n -= arr[i];
        }
        else
        {
            i++;
        }
    }

    return res;
}