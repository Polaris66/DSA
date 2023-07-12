#include <bits/stdc++.h>
using namespace std;

int recursion(int x, vector<int> &c){
    if(x<0) return INT_MAX;
    if(x==0) return 0;

    int mini = INT_MAX;
    for(auto coin: c){
        int ans = recursion(x-coin,c);
        if(ans!=INT_MAX){
            mini = min(ans+1, mini);
        }
    }
    return mini;
}

int memoization(int x, vector<int> &c, vector<int> &memo){
    if(x<0) return INT_MAX;

    if(x==0) return 0;

    if(memo[x]!=-1) return memo[x];

    int mini = INT_MAX;
    for(auto coin: c){
        int ans = memoization(x-coin, c, memo);
        if(ans!=INT_MAX){
            mini = min(ans+1, mini);
        }
    }

    memo[x] = mini;
    return memo[x];
}

int tabulation(int x, vector<int> &c){
    vector<int> dp(x+1, INT_MAX);

    dp[0] = 0;
    for(int i = 1; i < x+1; i++){
        int mini = INT_MAX;
        for(auto coin: c){
            if(i - coin > -1){
                int ans = dp[i-coin];
                if(ans!= INT_MAX){
                    mini = min(ans+1, mini);
                }
            }
        }
        dp[i] = mini;
    }

    return dp[x];
}

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> c(n);
    for(auto &y:c){
        cin>>y;
    }

    // if(recursion(x,c)==INT_MAX) cout<<-1<<endl;
    // else{
    //     cout<<recursion(x,c)<<endl;
    // }

    // vector<int> memo(x+1,-1);

    // int res = memoization(x,c,memo);
    
    int res = tabulation(x,c);

    if(res==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<res<<endl;
    }
}

