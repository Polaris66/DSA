#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const int INF = 1e9;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> c(n);
    for(auto &x:c){
        cin>>x;
    }
    vector<int> dp(k+1,INF);
    dp[0]=0;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(c[j]<=i && dp[i-c[j]]!=INF){
                dp[i] = min(dp[i],dp[i-c[j]]+1);
            }
        }
    }

    if(dp[k]==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[k]<<endl;
    }
}