#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll sum_of_digits(ll n){
    ll res = 0;
    while(n){
        res += n%10;
        n/=10;
    }
    return res;
}

ll recursion(vector<ll> &S, ll n, ll i, ll prev_max){
    if(i > n-1){
        return 1;
    }

    ll res = 0;
    for(int j = prev_max+1; j < 1001; j++){
        if(sum_of_digits(j)==S[i])
            {
                res += recursion(S,n,i+1,j)%mod;
            }
    }
    return res%mod;
}

ll memoization(vector<ll> &S, ll n, ll i, ll prev_max, vector<vector<ll>> &memo)
{
    if (i > n - 1)
    {
            return 1;
    }

    if(memo[i][prev_max]!=-1)
    {
        return memo[i][prev_max]%mod;
    }

    ll res = 0;
    for (int j = prev_max + 1; j < 1001; j++)
    {
            if (sum_of_digits(j) == S[i])
            {
                res += recursion(S, n, i + 1, j) % mod;
            }
    }
    memo[i][prev_max] = res % mod;
    return memo[i][prev_max];
}

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        vector<ll> S(n);
        for(auto &x: S){
            cin>>x;
        }
    
        // cout<<recursion(S,n,0,0)<<endl;

        vector<vector<ll>> memo(n, vector<ll> (1001,-1));
        cout<<memoization(S,n,0,0,memo);
    }
}