#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int binarySearch(int arr[], int n, int target){
	int l = 0;
	int r = n-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(arr[mid] <= target){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return (l+r)/2;
}

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	int max = -1;
	for(int i = 0; i <= n; i++){
				
	}
	//printArray(arr,n);
	
}
//sort
//binary search for all values if its equal to value diff condition else diff condition
