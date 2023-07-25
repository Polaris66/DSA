#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int first = i;
            int second = n;

            bool possible = true;
            for (int j = 0; j < k - 2; j++)
            {
                int fx = first;
                first = second - fx;
                second = fx;
                possible &= (first <= second);
                possible &= (min(first, second) >= 0);
                if (!possible)
                    break;
            }

            if (possible)
            {
                res++;
            }
        }

        cout << res << endl;
    }
}
