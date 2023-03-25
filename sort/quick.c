#include <stdio.h>

int partition(int *arr, int lb, int ub){
	int start = lb;
	int end = ub;
	int pivot = arr[lb];
	while(start<end){
		while(arr[start]<=pivot){
			start++;
		}
		while(arr[end]>pivot){
			end--;
		}
		if(start<end){
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}
}

void quickSort(int *arr, int n){
	
}

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	mergeSort();
}
