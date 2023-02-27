#include <stdio.h>

int main(){
	int n, k, t;
	scanf("%d",&n);
	scanf("%d",&k);
	scanf("%d",&t);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	int count = 0;
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum+=arr[i];
	}
	if((sum/k)>=t){
		count+=1;
	}
	
	for(int i = 1; i <= n-k; i++){
		sum+=arr[i+k-1];
		sum-=arr[i-1];
		if((sum/k)>=t){
		count+=1;
		}
	}
	printf("%d\n",count);
}
