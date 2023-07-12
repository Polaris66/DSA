#include <bits/stdc++.h>

#define ll long long


using namespace std;

int main(){
	const int mod = 1000000007;
	ll n, x;
	cin>>n>>x;
	
	vector<ll> c(n);
	for(ll i = 0; i < n; i++){
		cin>>c[i];
	}
	
	vector<ll> dp(x+1, 0);
	
	dp[0] = 0;
	
	for(ll i = 0; i < n; i++){
		if(c[i] <= x)
			dp[c[i]] = 1;
	}
	
	for(ll i = 1; i < x+1; i++){
		ll sum = 0;
		for(ll j = 0; j < n; j++){
			if((i - c[j]) > -1){
				sum += (dp[i-c[j]]%mod);
			}
		}
		dp[i] += (sum % mod);
	}
	
	cout<<dp[x];
}
