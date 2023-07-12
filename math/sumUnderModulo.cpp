#define ull unsigned long long

#include <bits/stdc++.h>

using namespace std;


int sumUnderModulo(ull a, ull b){
	ull mod = pow(10,9) + 7;
	return (int)((a%mod)+(b%mod));
}

int main(){
	ull a, b;
	scanf("%llu %llu",&a,&b);
	
	printf("%d",sumUnderModulo(a,b));
}
