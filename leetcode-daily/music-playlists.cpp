#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

// dp[i][j] = no. of playlists with i songs and j unique songs
// dp[i][j] = dp[i-1][j] * (j - k) + dp[i-1][j-1] * (n-j+1)
int numMusicPlaylists(int n, int goal, int k)
{
    vector<vector<ll>> dp(goal + 1, vector<ll>(n + 1, 0));

    dp[0][0] = 1LL;
    for (int i = 1; i <= goal; i++)
    {
        for (int j = 1; j <= min(i, n); j++)
        {
            if (j > k)
                dp[i][j] += (dp[i - 1][j] * (j - k)) % MOD;
            dp[i][j] += (dp[i - 1][j - 1] * (n - j + 1)) % MOD;
            dp[i][j] %= MOD;
        }
    }
    return dp[goal][n];
}
int main()
{
    int n, goal, k;
    cin >> n >> goal >> k;
    cout << numMusicPlaylists(n, goal, k) << endl;
}