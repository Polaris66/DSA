#include <bits/stdc++.h>
using namespace std;

#define ll long long

void recursion(vector<ll> nums, ll i, ll sum, set<ll>& res){
    if(i == -1){
        res.insert(sum);
        return;
    };
    recursion(nums, i-1, sum, res);
    recursion(nums, i-1, sum+nums[i], res);
}

void memoization(vector<ll> nums, ll i, ll sum, set<ll> &res, vector<vector<ll>> &memo){
    if(i==-1){
        res.insert(sum);
        return;
    }

    if(memo[i][sum]!=-1) return;

    memoization(nums, i-1, sum, res,memo);
    memoization(nums, i-1, sum+nums[i],res,memo);
    memo[i][sum] = 1;
}

int main(){
    ll n;
    cin>>n;

    vector<ll> nums(n);
    for(auto &x: nums){
        cin>>x;
    }   

    set<ll> res;
    

    // recursion(nums, n-1, 0, res);

    ll sum = 0;
    for (auto x : nums)
    {
        sum += x;
    }

    vector<vector<ll>> memo(n, vector<ll> (sum+1, -1));
    memoization(nums, n-1, 0, res, memo);

    cout<<res.size()-1<<endl;
    for(auto x: res){
        if(x!=0)
        cout<<x<<" ";
    }
}
