#include <bits/stdc++.h>
using namespace std;

static bool cmp(Item &a, Item &b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    double res = 0;
    double curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr + arr[i].weight < W)
        {
            res += arr[i].value;
            curr += arr[i].weight;
        }
        else
        {
            double remaining = W - curr;
            res += (remaining) * ((double)arr[i].value) / (double)arr[i].weight;
            break;
        }
    }

    return res;
}