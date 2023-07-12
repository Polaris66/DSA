#include <bits/stdc++.h>


using namespace std;
int main(){
	long long int n;
	scanf("%lld",&n);
	
	long long int res = n*(n+1)/2;
	long long int x;
	for(long long int i = 0; i < n-1; i++){
		scanf("%lld",&x);
		res-=x;
	}
	printf("%lld\n",res);
}
