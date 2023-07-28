#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A)
{
    vector<int> vals;
    int N = A.size();
    int i = 0;
    vals.push_back(A[i]);

    while ((i <= N) || vals[i] > 1)
    {
        int div = vals[i] / 2;
        vals[i] -= div * 2;
        if ((i + 1) < N)
        {
            div += A[i + 1];
        }
        vals.push_back(div);
        i++;
    }

    int res = 0;
    for (int v : vals)
    {
        res += v;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << solution(A) << endl;
}