#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		ll n;
	scanf("%lld",&n);
	
	ll sum = 0;
	while(n>=1){
		sum += n;
		n = floor(n/2);
	}
	
	printf("%lld\n",sum);
	
	}
	}
