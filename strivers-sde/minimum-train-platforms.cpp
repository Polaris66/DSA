#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int cnt = 0;
    int res = 0;

    int i = 0;
    int j = 0;

    while ((i < n) && (j < n))
    {
        if (arr[i] <= dep[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }

        res = max(res, cnt);
    }

    return res;
}