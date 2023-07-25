#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[i - 1]);
    }
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

    rotate(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}