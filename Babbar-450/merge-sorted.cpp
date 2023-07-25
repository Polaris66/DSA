#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int right = n - 1;
    int left = 0;
    while (right >= 0 && left <= m)
    {
        if (arr1[right] > arr2[left])
        {
            swap(arr1[right], arr2[left]);
            right--;
            left++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    long long arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cin >> m;
    long long arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    merge(arr1, arr2, n, m);

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}