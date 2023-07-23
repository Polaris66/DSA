#define ll long long

#include <bits/stdc++.h>
using namespace std;
ll maxSum(vector<ll> &a){
	ll sum = 0;
	for(auto x: a){
		sum+= abs(x);
	}
	return sum;
}

int noOfOperations(vector<ll> &a){
	
	int beginCounting = 0;
	int noOfOperations = 0;
	for(auto x : a){
		if(x<0 && beginCounting == 0){
			beginCounting = 1;
			
		}
		if(x>0){
			if(beginCounting){
				noOfOperations++;
				beginCounting = 0;
			}
		}
	}	
	
	if(beginCounting){
		noOfOperations++;
	}
	return noOfOperations;
}

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		int n;
		scanf("%d",&n);
		
		vector<ll> a;
		while(n--){
			ll x;
			scanf("%lld",&x);
			a.push_back(x);
		}
		
		printf("%lld ", maxSum(a));
		printf("%d\n",noOfOperations(a));
	}
}
