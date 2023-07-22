#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int N)
{
    int ptr = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[ptr++], arr[i]);
        }
    }
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

    solve(arr, N);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}