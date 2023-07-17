#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> &nums){
    int n = nums.size();

    int sum = nums[0];
    int maxi = nums[0];
    for(int i = 1; i < n; i++){
        sum += nums[i];
        maxi = max(sum, maxi);
        if(sum < 0){
            sum = 0;
        }
    }

    return maxi;
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    cout<<maxSubarray(nums)<<endl;
}