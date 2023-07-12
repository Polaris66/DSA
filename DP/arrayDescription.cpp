#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int recursion(vector<int> a, int m, int i, int n){
    if(i==n){
        return 1;
    }
    int ans = 0;
    if(a[i]!=0){
        if (i == 0)
        {
            ans += recursion(a,m,i+1,n) % mod;
        }
        else if (abs(a[i - 1] - a[i]) <= 1)
        {
            ans += recursion(a, m, i + 1,n) % mod;
        }
    }
    else{
        for(int j = 1; j <= m; j++){
            // Check If Possible
        if(i==0){
            a[i] = j; 
            ans += recursion(a,m,i+1,n) % mod;
        }
        else if ((abs(a[i - 1] - j) <= 1)){
            a[i] = j;
            ans += recursion(a, m, i + 1, n) % mod;
        }
        }
    }
    return ans%mod;
}

int tabulation(){
    return 1;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    for(auto &x: a){
        cin>>x;
    }

    cout<<recursion(a,m,0,n)<<endl;
}