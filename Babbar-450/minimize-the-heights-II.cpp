#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    sort(arr, arr + n);
    int res = arr[n - 1] - arr[0];
    int _max;
    int _min;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0)
            continue;
        _max = max(arr[n - 1] - k, arr[i - 1] + k);
        _min = min(arr[0] + k, arr[i] - k);
        if (_max >= _min)
            res = min(res, _max - _min);
    }

    return res;
}

int main()
{

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getMinDiff(arr, n, k) << endl;
}
