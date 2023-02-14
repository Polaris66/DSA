#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int findIndex(int *arr, int n, int i, int value){
	int l = i;
	int r = n-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(arr[mid]<=value){
			l = mid+1;
		}
		else{
			r = mid-1;
			}
		}
	return r;
}

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		int value = arr[i];
		i = findIndex(arr,n,i,value);
		count++;
	}
	printf("%d\n",count);
	//printArray(arr,n);
}
