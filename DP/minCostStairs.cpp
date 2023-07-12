#include <bits/stdc++.h>
using namespace std;

int recursion(int n, vector<int> &cost){
    if(n==0 || n==1) return 0;

    return min(recursion(n-1, cost)+cost[n-1], recursion(n-2, cost)+cost[n-2]);
}

int memoization(int n, vector<int> &cost, vector<int> & memo){
    if(n==0 || n==1) return 0;
    memo[0] = 0;
    memo[1] = 0;

    if(memo[n]!=-1) return memo[n];

    memo[n] = min(memoization(n-1,cost,memo)+cost[n-1], memoization(n-2,cost,memo)+cost[n-2]);
    return memo[n];
}

int tabulation(int n, vector<int> &c){
    vector<int> dp(n+1);
    if(n<2) return 0;
    dp[0] = 0;
    dp[1] = 0;

    for(int i = 2; i < n+1; i++){
        dp[i] = min(dp[i-1]+c[i-1],dp[i-2]+c[i-2]);
    }

    return dp[n];
}

int optimisation(int n, vector<int> &c){
    int prev1 = 0;
    int prev2 = 0;

    for(int i = 2; i < n+1; i++){
        int current = min(prev1+c[i-1], prev2+c[i-2]);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main(){
    int n;
    cin>>n;

    vector<int> c(n);
    for(auto &x: c){
        cin>>x;
    }

    // cout<<recursion(n,c)<<endl;

    // vector<int> memo(n+1, -1);
    // cout<<memoization(n,c,memo)<<endl;

    // cout<<tabulation(n,c)<<endl;

    cout << optimisation(n, c) << endl;
}


