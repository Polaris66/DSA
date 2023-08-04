#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void findDeduction(int *arr, int n, int target){
	int l = 0;
	int r = n-1;
	while(l<r){
		int mid = (l+r)/2;
		int val = arr[mid];
		if(val == target){
			printf("%d\n",val);
			return;	
		}
		if(val<target){
			l = mid+1;
		}
		else if(val>target){
			r = mid-1;
		}
	}
	printf("%d\n",arr[(l+r)/2]);
}

int main(){
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	findDeduction(arr,n,k);
}
