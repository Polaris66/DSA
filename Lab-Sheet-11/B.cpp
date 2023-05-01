#include <iostream>
#include <vector>

using namespace std;

int lcs(vector<int> &a, int n, vector<int> &b, int m){
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int maximum = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            maximum = max(maximum,dp[i][j]);
        }
    }
    return maximum;
}

int main(){
    int n, m;

    cin>>n;
    vector<int> a(n);
    for(auto &x:a){
        cin>>x;
    }

    cin>>m;
    vector<int> b(m);
    for(auto &x:b){
        cin>>x;
    }

    cout<<lcs(a,n,b,m);
}