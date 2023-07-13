#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

int recursion(int n){
    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }
    
    return ((n-1) * (recursion(n-2) + recursion(n-1))) % MOD ;
}

ll memoization(int n, vector<ll> &memo){
    if(n==1) return 0;
    if(n==2) return 1;

    if(memo[n]!=-1) return memo[n];

    memo[n] = ((n-1)%MOD) * (((memoization(n-1,memo) % MOD) + (memoization(n-2,memo) % MOD))%MOD);
    return memo[n]%MOD;
}

ll tabulation(int n){
    vector<ll> dp(n+1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i < n+1; i++){
        dp[i] = (((i-1) % MOD) * (((dp[i-1]%MOD) + (dp[i-2]%MOD))%MOD))% MOD;
    }
    return dp[n];
}

ll optimisation(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    ll a = 0;
    ll b = 1;
    for(int i = 3; i < n+1; i++){
        ll c = (((i-1) % MOD) * (((a % MOD) + (b%MOD))%MOD))%MOD;
        a = b;
        b = c;
    }

    return b;
}

int main(){
    int n;
    cin>>n;
    // cout<<recursion(n)<<endl;

    // vector<ll> memo(n+1,-1);
    // cout<<memoization(n, memo)<<endl;

    // cout<<tabulation(n)<<endl;

    cout<<optimisation(n)<<endl;
}