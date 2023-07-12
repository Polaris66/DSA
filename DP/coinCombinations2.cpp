#include <bits/stdc++.h>

#define mod 1000000007
using namespace std;

int recursion(int x, vector<int> &c, int min_index)
{
    if (x == 0)
        return 1;

    int res = 0;
    for (int i = min_index; i > -1; i--)
    {
        if ((x - c[i]) > -1)
        {
            res += recursion(x - c[i], c, i)%mod;
        }
    }

    return res;
}

int memoization(int x, vector<int> &c, int min_index, vector<vector<int>> &memo){
    if(x==0)
        return 1;
    
    if(memo[x][min_index]!=-1){
        return memo[x][min_index];
    }

    int res = 0;
    for(int i = min_index; i > -1; i--){
        if((x-c[i]) > -1){
            res += memoization(x-c[i], c, i, memo)%mod;
        }
    }
    
    memo[x][min_index] = res;
    return memo[x][min_index];
}

int tabulation(int x, vector<int> &c){
    int n = c.size();
    vector<vector<int>> dp(x+1, vector<int>(n,0));
    for(int i = 0; i < n; i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i < x + 1; i++){
        for(int j = 0; j < n; j++){
            int res = 0;
            for(int k = j; k > -1; k--){
                if(i-c[k] > -1){
                    res += dp[i-c[k]][k] % mod;
                }
            }
            dp[i][j] = res;
        }
    } 

    // for(int i = 0; i < x+1; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[x][n-1];
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (auto &y : c)
    {
        cin >> y;
    }
    // cout << recursion(x, c, n - 1) << endl;

    // vector<vector<int>> memo(x+1, vector<int> (n,-1));
    // cout<<memoization(x,c,n-1,memo)<<endl;

    cout<<tabulation(x,c)<<endl;
}