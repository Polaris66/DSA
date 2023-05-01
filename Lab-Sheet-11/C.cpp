#include <iostream>
#include <vector>

using namespace std;

int minimum(int a, int b, int c){
    int m = a;
    m = min(m,b);
    m = min(m,c);
    return m;
}
int editDistance(string a, int n, string b, int m){
    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = minimum(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1;
            }
        }
    }

    return dp[n][m];
}

int main(){
    int n;
    cin>>n;
    string a;
    cin>>a;

    int m;
    cin>>m;
    string b;
    cin>>b;

    cout<<editDistance(a,n,b,m);
}