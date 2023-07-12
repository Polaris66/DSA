#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll solve(ll n){
	vector<ll> dp(n+1,-1);

	// Base Case
	if(n==0) return 0;
	dp[0] = 0;
	
	if(n<10) return 1;
	for(int i = 1; i < 10; i++){
		dp[i] = 1;
	}
	
	for(int i = 10; i < n+1; i++){
		int temp = i;
		while(temp){
			int digit = temp%10;
			if((i - digit > -1) && dp[i-digit] != -1){
				if(dp[i] == -1){
					dp[i] = dp[i-digit] + 1;
				}
				else{
					dp[i] = min(dp[i], dp[i-digit] + 1);
				}
			}	
			temp/=10;
		}
	}
	
	return dp[n];
}

int main(){
	ll n;
	cin>>n;

	cout<<solve(n)<<endl;
}
