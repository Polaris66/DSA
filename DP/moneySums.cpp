#include <bits/stdc++.h>
using namespace std;

#define ll long long

void recursion(vector<ll> nums, int i, int sum, set<int>& res){
    if(i == -1){
        res.insert(sum);
        return;
    };
    recursion(nums, i-1, sum, res);
    recursion(nums, i-1, sum+nums[i], res);
}

int main(){
    
}