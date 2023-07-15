#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


ll nCr(ll n, ll r, vector<vector<ll>> &memo){
    
    if(n==0) return 1;
    if(n==r) return 1;
    if(n<r) return 0;
    if(r==0) return 1;

    if(memo[n][r]!=-1) return memo[n][r];

    memo[n][r] = nCr(n-1,r,memo) + nCr(n-1,r-1,memo);
    return memo[n][r];
}

ll solve(string s, int k){
    map<char, ll> ft;
    for(char x: s){
        ft[x]++;
    }

    if(ft.size() > k) return 0;

    ll res = 1;
    if(ft.size()==k){
        for(auto it = ft.begin(); it!=ft.end(); ++it){
            res *= it->second;
        }
    }
    return res % mod;

    res = 1;
    ll left = 0;
    for(auto it = ft.begin(); it != ft.end(); ++it)
    {
        if(it->second!=1){
            res * (it->second);
            left += it->second - 1;
        }
    }

    vector<vector<ll>> memo(left, vector<ll> (k-ft.size(),-1));

    res *= nCr(left, k-ft.size(), memo);
    return res % mod;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        cout<<solve(s,k)<<endl;
    }
}