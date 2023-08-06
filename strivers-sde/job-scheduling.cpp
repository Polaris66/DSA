#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int dead;
    int profit;
    int id;
};

bool cmp(Job &a, Job &b)
{
    if (a.profit == b.profit)
        return (a.dead > b.dead);
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    set<int> possible;
    for (int i = 1; i <= n; i++)
    {
        possible.insert(i);
    }

    int res = 0;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        Job curr = arr[i];
        auto closest = possible.upper_bound(curr.dead);
        if (closest != possible.begin())
        {
            closest--;
            res++;
            p += curr.profit;
            possible.erase(closest);
        }
    }

    return {res, p};
}