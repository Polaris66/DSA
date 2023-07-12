#define ull unsigned long long

#include <bits/stdc++.h>

using namespace std;

int multiplicationUnderModulo(ull a, ull b){
	ull M = pow(10,9) + 7;
	
	return (int) (((a%M)*(b%M))%M);
}

int main(){
	ull a, b;
	scanf("%llu %llu", &a, &b);
	
	printf("%d", multiplicationUnderModulo(a,b));
}
