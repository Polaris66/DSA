#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll tabulation(vector<ll> nums)
{
    ll n = nums.size();
    vector<ll> dp(n, 0);

    dp[0] = nums[0];
    for (ll i = 1; i < n; i++)
    {
        ll include = nums[i];
        if (i - 2 > -1)
        {
            include += dp[i - 2];
        }
        ll exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}

long long int houseRobber(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    int n = nums.size();
    vector<ll> first;
    vector<ll> last;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            first.push_back(nums[i]);
        if (i != n - 1)
            last.push_back(nums[i]);
    }

    return max(tabulation(first), tabulation(last));
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }

    cout<<houseRobber(nums)<<endl;

}