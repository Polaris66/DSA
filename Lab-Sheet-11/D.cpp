#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int> &a,int n){
    int dp[n][n];
    for(int i = n-1; i > -1; i--){
        for(int j= 0; j < n; j++){
            if(i==j){
                dp[i][j] = a[i];
            }
            else if(i>j){
                dp[i][j] = 0;
            }
            else dp[i][j] = max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x:a){
        cin>>x;
    }   
    int sum = 0;
    for(auto x:a){
        sum+=x;
    }
    int v_score = maxSum(a,n);
    int h_score = sum-v_score;
    if(v_score>h_score){
        cout<<"Vidyateja"<<endl;
    }
    else{
        cout<<"Hom"<<endl;
    }
}