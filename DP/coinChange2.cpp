#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int recursion(vector<int> &coins, int n, int x, int index)
{
    if(x == 0){
        return 1;
    }

    int res = 0;
    for(int i = index; i < n; i++){
        if(x - coins[i] > -1){
            res += recursion(coins, n, x-coins[i], i);
        }
    }
    return res;
}

ll memoization(vector<int> &coins, int n, int x, int index, vector<vector<ll>> &memo){
    
    if(x==0){
        return 1;
    }

    if(memo[x][index] != -1){
        return memo[x][index] % MOD;
    }

    ll res = 0;
    for(int i = index; i < n; i++){
        if(x - coins[i]> -1){
            res += memoization(coins, n, x-coins[i], i, memo) % MOD;
        }
    }
    memo[x][index] = res % MOD;
    return memo[x][index];
}

ll tabulation(vector<int> &coins, int x){
    int n = coins.size();

    vector<vector<ll>> dp(x+1, vector<ll>(n,0));

    for(int i = 0; i < x + 1; i++){
        for(int j = n-1; j > -1; j--){
            if(i==0){
                dp[i][j] = 1;
            }
            else{
                ll res = 0;
                for(int k = j; k < n; k++){
                    if(i-coins[k] > -1){
                        res += dp[i-coins[k]][k] % MOD;
                    }
                }
                dp[i][j] = res % MOD;
            }
        }
    }

    return dp[x][0] % MOD;
}

int flipOrder(vector<int> &c, int x){
    vector<int> dp(x+1, 0);
    dp[0] = 1;

    int n = c.size();
    for(int i = 0; i < n; i++){
        for(int amt = 1; amt < x+1; amt++){
            if(amt-c[i] > -1){
                dp[amt] += dp[amt-c[i]] % MOD;
                dp[amt] %= MOD;
            }
        }
    }

    return dp[x]%MOD;
}

int main(){


    int n;
    cin>>n;

    int x;
    cin >> x;

    vector<int> coins(n);
    for(auto &coin: coins){
        cin>>coin;
    }

    sort(coins.rbegin(), coins.rend());

    // cout<<recursion(coins, n, x, 0)<<endl;

    // vector<vector<ll>> memo(x+1, vector<ll> (n, -1));
    // cout<<memoization(coins, n, x, 0, memo)<<endl;

    // cout<<tabulation(coins, x)<<endl;

    cout<<flipOrder(coins, x)<<endl;
}