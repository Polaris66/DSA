#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void findSqrt(long int n){
	long int l = 0;
	long int r = n;
	int count = 0;
	while(l!=r){
		long mid = (l+r)/2;
		if((mid*mid) < n){
			l = mid + 1;
		}
		else if((mid*mid) > n){
			r = mid - 1;
		}
		count++;
	}
	printf("%ld\n",l);
}

int main(){
	long int n;
	scanf("%ld",&n);
	findSqrt(n);
}
