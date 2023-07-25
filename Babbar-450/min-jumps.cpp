#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }

    if (arr[0] == 0)
    {
        return -1;
    }

    int i = 1;
    int stepsLeft = arr[0];
    int maxReachable = arr[0];
    int jumps = 1;

    while (i < n)
    {
        if (i == n - 1)
        {
            return jumps;
        }
        maxReachable = max(maxReachable, i + arr[i]);
        stepsLeft--;

        if (stepsLeft == 0)
        {
            if (maxReachable == i)
            {
                return -1;
            }
            jumps++;
            stepsLeft = maxReachable - i;
        }

        i++;
    }

    return 0;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << minJumps(arr, N);
}