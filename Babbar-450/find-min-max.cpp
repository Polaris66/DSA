#include <bits/stdc++.h>
using namespace std;

int find_min_max(int A[], int N)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        int x = A[i];
        maxi = max(maxi, x);
        mini = min(mini, x);
    }

    return mini + maxi;
}

int main()
{
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << find_min_max(A, N) << endl;
}