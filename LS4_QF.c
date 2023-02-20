#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int arr[], int n){
	
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}

int main(){
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	
	int ft[n];
	for(int i = 0; i < n; i++){
		ft[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d",&val);
		ft[val-1]++;
	}
	
	int ans[k];
	for(int i = 0; i < k; i++){
		ans[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		if(ft[i]>ans[0]){
			for(int j = k-1; j > 0; j++){
				ans[j] = ans[j-1];
			} 
			ans[0] = i+1;
		}	
	}
	printArray(ans,k);
}
