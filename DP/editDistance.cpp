#include <bits/stdc++.h>
using namespace std;

int recursion(string a, string b, int i, int j, vector<vector<int>> &memo){
    if(i==(int)a.size()){
        return b.size() - j;
    }
    if(j==(int)b.size()){
        return a.size() - i;
    }
    
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    if(a[i]==b[j]){
        memo[i][j] = recursion(a, b, i + 1, j + 1, memo); 
        return memo[i][j];
    }
    int o = INT_MAX;
    int replace_cost = recursion(a,b,i+1,j+1, memo);
    o = min(o, replace_cost);
    int delete_cost = recursion(a,b,i+1,j, memo);
    o = min(o,delete_cost);
    int insert_cost = recursion(a,b,i,j+1, memo);
    o = min(o,insert_cost);
    memo[i][j] = o+1;
    return memo[i][j];
}

int tabulation(string a, string b){
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = m; i > -1; i--){
        for(int j = n; j > -1; j--){
            if(i==m){
                dp[i][j] = n-j;
            }
            else if(j==n){
                dp[i][j] = m-i;
            }
            else if(a[i]==b[j]){
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                int o = INT_MAX;
                int replace_cost = dp[i+1][j+1];
                o = min(o, replace_cost);
                int delete_cost = dp[i+1][j];
                o = min(o, delete_cost);
                int insert_cost = dp[i][j+1];
                o = min(o, insert_cost);
                dp[i][j] = o + 1;
            }
        }
    }
    return dp[0][0];
}

int main(){
    string a;
    string b;
    cin>>a>>b;

    // vector<vector<int>> memo(a.size(),vector<int>(b.size(),-1));
    // cout<<recursion(a,b,0,0,memo);

    cout<<tabulation(a,b)<<endl;

}