#include <stdio.h>

int main(){
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	int arr[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	int l = 0;
	int r = 0;
	int sum = arr[0];
	int count = 0;
	if(!(sum%k)){
		count++;
	}
}
