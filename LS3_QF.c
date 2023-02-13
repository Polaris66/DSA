#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	//printArray(arr,n);
}
