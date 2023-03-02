#include <stdio.h>
#include <math.h>

long long death(int head, int remaining, int step, int left){
	if(remaining==1){
		return head;
	}
	if(left==1 || (left==0 && remaining%2==1)){
		head+=step;
	}
	if(left){
		left = 0;
	}
	else{
		left = 1;
	}
	head = death(head,remaining/2,2*step,left);
	return head;
}

int main(){
	long long int n;
	scanf("%lld",&n);
	
	printf("%lld\n",death(1,n,1,1));
}
