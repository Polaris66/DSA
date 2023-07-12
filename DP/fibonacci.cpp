#include <bits/stdc++.h>
using namespace std;

int recursion(int n){
    if(n==0) return 0;
    if(n<3) return 1;
    return recursion(n-1)+recursion(n-2);
}

int memoization(int n, vector<int>& dp){
    if(n==0 || n==1) return n;

    if(dp[n]!=-1) return dp[n];

    dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
    return dp[n];
}

int tabulation(int n){
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int optimized(int n){
    vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n+1; i++){
        dp[2] = dp[1] + dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    return dp[1];
}

int main(){
    int t;
    cin>>t;
    int n;
    cin>>n;
    if(t==1)
    cout<<recursion(n)<<endl;
    if(t==2){
    vector<int> dp(n + 1, -1);
    cout << memoization(n, dp) << endl;
    }
    if(t==3)
    cout<<tabulation(n)<<endl;
    if(t==4)
    cout<<optimized(n)<<endl;
}