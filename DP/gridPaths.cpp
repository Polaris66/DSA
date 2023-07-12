#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int recursion(vector<vector<char>>& grid, int n, int i, int j){
    if(grid[i][j]=='*'){
        return 0;
    }

    if((i==n-1) && (j==n-1)){
        return 1;
    }
    if(i==n-1){
        return recursion(grid, n, i, j + 1) % mod;
    }
    if(j==n-1){
        return recursion(grid, n, i+1, j) % mod;
    }
    return recursion(grid,n,i+1,j) % mod + recursion(grid,n,i,j+1) % mod;
}

int tabulation(vector<vector<char>>& grid, int n){
    vector<vector<int>> dp(n, vector<int>(n,0));

    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]=='*'){
                dp[i][j] = 0;
            }
            else{
                if(i>0){
                    dp[i][j] += dp[i - 1][j] % mod;
                }
                if(j>0){
                    dp[i][j] += dp[i][j-1] % mod;
                }
            }
        }
    }

    return dp[n-1][n-1] % mod;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }

    // cout<<recursion(grid,n,0,0)<<endl;
    cout<<tabulation(grid, n)<<endl;
}