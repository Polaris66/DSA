#define ll long long
int NthRoot(int n, int m)
{
    int l = 1;
    int r = m;

    int ans = -1;

    while (l <= r)
    {
        int mid = (r - l) / 2 + l;

        long long x = 1;
        for (int i = 1; i <= n; i++)
        {
            x *= mid;

            if (x > 1LL * m)
            {
                break;
            }
        }

        if (x == 1LL * m)
        {
            ans = mid;
            break;
        }
        else if (x > m)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}