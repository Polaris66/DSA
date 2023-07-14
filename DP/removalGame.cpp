#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll recursion(vector<ll>& a, ll i, ll j, ll n){
    if(i > n-1) return 0;
    if(j < 0) return 0;
    if(j < i) return 0;

    ll take_i = a[i] + min(recursion(a,i+2,j,n), recursion(a,i+1,j-1,n));
    ll take_j = a[j] + min(recursion(a,i+1,j-1,n), recursion(a,i,j-2,n));
    
    return max(take_i, take_j);
}

ll memoization(vector<ll> &a, ll i, ll j, ll n, vector<vector<ll>> &memo){
    if(i > n-1) return 0;
    if(j < 0) return 0;
    if(j < i) return 0;

    if(memo[i][j] != -1) return memo[i][j];

    ll take_i = a[i] + min(memoization(a,i+2,j,n,memo), memoization(a,i+1,j-1,n,memo));
    ll take_j = a[j] + min(memoization(a,i+1,j-1,n,memo), memoization(a,i,j-2,n,memo));
    
    memo[i][j] = max(take_i, take_j);
    return memo[i][j];
}

int main(){
    ll n;
    cin>>n;

    vector<ll> a(n);
    for(auto &x: a){
        cin>>x;
    }

    // cout<<recursion(a,0,n-1,n)<<endl;

    vector<vector<ll>> memo(n, vector<ll> (n,-1));
    cout<<memoization(a,0,n-1,n,memo)<<endl;
}