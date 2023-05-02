#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n+1), value(n+1);
    int total_value = 0;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
        total_value += value[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(total_value+1, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total_value; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= value[i]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-value[i]] + weight[i]);
            }
        }
    }
    int ans = 0;
    for (int j = total_value; j >= 0; j--) {
        if (dp[n][j] <= w) {
            ans = j;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
