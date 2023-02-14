#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int findLastIndex(int *arr, int n, int l, int target){
	int result = -1;
	int r = n - 1;
	while(l<=r){
		int mid = l + (r-l)/2;
		printf("%d %d\n",mid,target);
		if(arr[mid]==target){
			result = mid;
			l = mid + 1;
		}
		else if (arr[mid]<target){
			l = mid+1;		
		}
		else{
			r = mid;
		}
	}	
	return result+1;
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
		i = findLastIndex(arr,n,i,arr[i]);
		count++;
	}
	printf("%d\n",count);
	//printArray(arr,n);
}
