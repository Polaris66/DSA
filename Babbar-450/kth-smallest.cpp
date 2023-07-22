#include <bits/stdc++.h>
using namespace std;

int sort_approach(int arr[], int l, int r, int k)
{
    sort(arr + l, arr + r + 1);
    return arr[k - 1];
}

int partition(int arr[], int l, int r)
{
    int n = l - r + 1;
    int pivot = r;

    int p = l;

    swap(arr[pivot], arr[r]);
    for (int i = l; i < r; i++)
    {
        if (arr[i] <= arr[r])
        {
            swap(arr[p], arr[i]);
            p++;
        }
    }

    swap(arr[p], arr[r]);
    return p;
}

int quickSelect(int arr[], int l, int r, int k)
{
    if (l <= r)
    {
        int pivot = partition(arr, l, r);
        if (pivot == k - 1)
        {
            return arr[pivot];
        }

        if (pivot > k - 1)
        {
            return quickSelect(arr, l, pivot - 1, k);
        }

        return quickSelect(arr, pivot + 1, r, k);
    }
    return -1;
}

int main()
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int K;
    cin >> K;

    // cout << sort_approach(arr, 0, N - 1, K);
    srandom(time(0));
    cout << quickSelect(arr, 0, N - 1, K);
}