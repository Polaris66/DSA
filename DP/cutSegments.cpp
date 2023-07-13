#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int x, int y, int z){
    if(n < 0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }

    int segments = INT_MIN;
    int using_x = recursion(n-x,x,y,z);
    segments = max(using_x, segments);
    int using_y = recursion(n-y,x,y,z);
    segments = max(using_y,segments);
    int using_z = recursion(n-z,x,y,z);
    segments = max(using_z, segments);

    if(segments == INT_MIN){
        return segments;
    } 
    return segments + 1;
}

int memoization(int n, int x, int y, int z, vector<int> &memo){
    if(n < 0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }

    if(memo[n]!= -1){
        return memo[n];
    }

    int segments = INT_MIN;
    segments = max(segments, memoization(n - x, x, y, z, memo));
    segments = max(segments, memoization(n - y, x, y, z,memo));
    segments = max(segments, memoization(n - z, x, y, z, memo));

    if(segments == INT_MIN){
        memo[n] = segments;
    }
    else{
        memo[n] = segments + 1;
    }
    return memo[n];
}

int tabulation(int n, int x, int y, int z){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i = 1; i < n+1; i++){
        if(i-x > -1 && dp[i-x]!=-1) 
            dp[i] = max(dp[i],dp[i-x]);
        if(i-y > -1 && dp[i-y]!=-1) 
            dp[i] = max(dp[i],dp[i-y]);
        if (i - z > -1 && dp[i-z]!=-1)
            dp[i] = max(dp[i], dp[i - z]);
        if(dp[i]!=-1){
            dp[i]++;
        }
    }
    return dp[n]==-1? 0 : dp[n];
}

int main(){
    int n, x, y, z;
    cin>>n>>x>>y>>z;

    // int res = recursion(n,x,y,z);
    
    // vector<int> memo(n+1,-1);
    // int res = memoization(n,x,y,z,memo);

    // if(res==INT_MIN){
    //     cout<<0<<endl;
    // }
    // else{
    //     cout<<res<<endl;
    // }

    cout<<tabulation(n,x,y,z);
}