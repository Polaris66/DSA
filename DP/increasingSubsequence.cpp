#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll recursion(vector<int> &nums, int n, int i, int prev_max){
    // Base Case
    if(i == n){
        return 0;
    }

    // Recursive Case
    // Include
    ll include = 0;
    if(prev_max == -1 || nums[i] > nums[prev_max]){
        include = recursion(nums, n, i+1, i) + 1;
    }

    // Exclude
    ll exclude = recursion(nums, n, i+1, prev_max);
    return max(include, exclude);
}

int memoization(vector<int> &nums, int n, int i, int prev_max, vector<vector<int>> &memo)
{
    // Base Case
    if (i == n)
    {
        return 0;
    }

    if(memo[i][prev_max+1] != -1){
        return memo[i][prev_max+1];
    }

    // Recursive Case
    // Include
    int include = 0;
    if (prev_max == -1 || nums[i] > nums[prev_max])
    {
        include = memoization(nums, n, i + 1, i, memo) + 1;
    }

    // Exclude
    int exclude = memoization(nums, n, i + 1, prev_max, memo);
    memo[i][prev_max+1] = max(include, exclude);
    
    return memo[i][prev_max+1];
}

int tabulation(vector<ll> &nums){
    int n = nums.size();
    vector<vector<ll>> dp(n+1, vector<ll> (n+1,0));

    for(ll i = n-1; i > -1; i--){
        for(ll prev_max = i-1; prev_max > -2; prev_max--){
            ll include = 0;
            if(prev_max == -1 || nums[i] > nums[prev_max]){
                include = dp[i+1][i+1] + 1;
            }
            ll exclude = dp[i+1][prev_max+1];

            dp[i][prev_max+1] = max(include, exclude);
        }
    }    

    return dp[0][0];
}

int optimisation(vector<ll> &nums){
    int n = nums.size();
    vector<ll> currRow(n + 1, 0);
    vector<ll> nextRow(n + 1, 0);

    for (ll i = n - 1; i > -1; i--)
    {
        for (ll prev_max = i - 1; prev_max > -2; prev_max--)
        {
            ll include = 0;
            if (prev_max == -1 || nums[i] > nums[prev_max])
            {
                include = nextRow[i + 1] + 1;
            }
            ll exclude = nextRow[prev_max + 1];

            currRow[prev_max + 1] = max(include, exclude);

        }
        nextRow = currRow;
    }

    return nextRow[0];
}

int binarySearch(vector<int> a, int n){
    vector<int> ans;
    ans.push_back(a[0]);

    for(int i = 1; i < n; i++){
        if(a[i] > ans.back()){
            ans.push_back(a[i]);
        }
        else{
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }

    return ans.size();
    }

// 10^12

int main(){
    ll n;
    cin>>n;

    vector<int> nums(n);
    for(ll i = 0; i < n; i++){
        cin>>nums[i];
    }

    // cout<<recursion(nums, n, 0, -1)<<endl;

    // vector<vector<int>> memo(n, vector<int> (n+1, -1));
    // cout << memoization(nums, n, 0, -1, memo) << endl;

    // cout<<tabulation(nums)<<endl;

    // cout<<optimisation(nums)<<endl;

    cout<<binarySearch(nums, n)<<endl;
}