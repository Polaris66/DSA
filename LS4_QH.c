#include <stdio.h>

long long int pairs(long long int n){
	return n*(n-1)/2;
}

int main(){
	long long int n;
	long long int m;
	scanf("%lld",&n);
	scanf("%lld",&m);
	long long int maximum = pairs(n-m+1);
	long long int minimum = 0;
	for(long long int i = 0; i < m-1; i++){
		minimum+=pairs(n/m);
	}
	minimum+=pairs((n-(m-1)*(n/m)));
	printf("%lld %lld\n",minimum,maximum); 
}
