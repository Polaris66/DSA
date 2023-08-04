#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void findSqrt(long int n){
	long int l = 0;
	long int r = n;
	while(l<=r){
		long int mid = (l+r)/2;
		if((mid*mid) < n){
			l = mid + 1;
		}
		else if((mid*mid) > n){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%ld\n",(l+r)/2);
}

int main(){
	long int n;
	scanf("%ld",&n);
	findSqrt(n);
}
