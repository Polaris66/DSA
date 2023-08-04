#include <stdio.h>

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int n; 
	int q;
	
	
	scanf("%d",&n);
	
	
	scanf("%d",&q);
	int arr[q];
	for(int i = 0; i < q; i++){
		scanf("%d",&arr[i]);
	}
	
	
	int sieve[n-1];
	for(int i = 0; i < n-1; i++){
		sieve[i] = -1;
	}
	
	for(int i = 2; i <=n; i++){
		if(sieve[i-2] == -1){
			sieve[i-2] = 1;
			for(int j = 2; i*j <= n; j++){
				sieve[(i*j)-2] = 0;
			}
		}
	}
	for(int i = 0; i < q; i++){
		int sum = 0;
		for(int j = 2; j <= arr[i]; j++){
			sum+=sieve[j-2];
		}
		printf("%d ",sum);
	}
}
