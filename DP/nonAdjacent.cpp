#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> &nums, int i){
    if(i < 0){
        return 0;
    }

    if(i == 0){
        return nums[0];
    }
    int include = nums[i] + recursion(nums, i-2);
    int exclude = recursion(nums, i-1);
    return max(include, exclude);
}

int memoization(vector<int> &nums, int i, vector<int> &memo){
    if(i < 0){
        return 0;
    }
    if(i==0){
        return nums[0];
    }

    if(memo[i]!=-1){
        return memo[i];
    }

    int include = nums[i] + memoization(nums, i-2, memo);
    int exclude = memoization(nums, i-1, memo);

    memo[i] = max(include, exclude);
    return memo[i];
}

int tabulation(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        int include = nums[i];
        if(i >=  2){
            include += dp[i-2];
        }
        dp[i] = max(include, dp[i-1]);
    }

    return dp[n-1];
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }

    // cout<<recursion(nums,n-1)<<endl;

    // vector<int> memo(n,-1);
    // cout<<memoization(nums,n-1,memo);

    cout<<tabulation(nums)<<endl;
}
