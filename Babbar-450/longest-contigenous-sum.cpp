#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long res = INT_MIN;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > res)
        {
            res = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxSubarraySum(arr, n) << endl;
}