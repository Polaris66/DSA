#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int> &a){
    int n = a.size()-1;
    int dp[n][n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for(int len = 2; len <= n; len++){
        for(int i = 0; i <= n-len; i++){
            int j = i + len -1;
            for(int k = i; k < j; k++){
                int q = dp[i][k]+dp[k+1][j] +a[i]*a[k+1]*a[j+1]; 
                if(q<dp[i][j]){
                    dp[i][j]=q;
                }
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n+1);
    for(auto &x:a){
        cin>>x;
    }

    cout<<matrixChainMultiplication(a);
}