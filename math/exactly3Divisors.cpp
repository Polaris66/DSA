#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int exactly3Divisors(int n){
	int ans = 0;
	
	for(int i = 2; i*i <= n;i++){
		if(isPrime(i)){ans++;}	
	}
	
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",exactly3Divisors(n));
}
