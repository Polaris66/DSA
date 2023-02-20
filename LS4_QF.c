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
	
	int max[k];
	
	for(int i = 0; i < k; i++){
		int maximum = -1;
		for(int j = 0; j < n; j++){
			if(ft[j]>=maximum){
				maximum = ft[j];
			}
		}
		for(int j = 0; j < n; j++){
			if(ft[j] == maximum){
				max[i] = j+1;
				ft[j] = -1;
				break;
			}
		}
	}
	printArray(max,k);
}
