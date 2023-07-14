#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

// Arrays that can be made with putting x at i
ll recursion(vector<int> a, int m, int i, int x, int n){
    
    if(i < 0) return 0;
    if(x > m) return 0;
    if(x < 1) return 0;

    if(a[i]!=0 && a[i]!=x){
        return 0;
    }

    ll ways = 0;
    ways += recursion(a, m, i - 1, x + 1, n) % mod;
    ways += recursion(a, m, i - 1, x - 1, n) % mod;
    ways += recursion(a, m, i - 1, x, n) % mod;
    return ways%mod;    
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }

    cout<<recursion(nums,m,n-1,m,n)<<endl;
}