#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void findSteps(long int n, long int target){
	long int l = 1;
	long int r = n-1;
	while(l<r){
		long int mid = (l+r)/2;
		long int sum = mid*(mid+1)/2;
		if(sum<target){
			l = mid + 1;		
		}
		else if(sum>target){
			r = mid - 1;
		}
		else{
			break;
		}
	}	
	printf("%ld\n",n-1-((l+r)/2));
}

int main(){
	long int n;
	scanf("%ld",&n);
	long int target = n*(n-1)/2;
	target = target - (target/2);
	findSteps(n,target);
}
