#include <stdio.h>


void countSort(int *arr, int n){
	
	int max = arr[0];
	for(int i = 1; i < n; i++){
		if(max>arr[i]){
			max = arr[i];
		}
	}

	int count[max+1];
	for(int i = 0; i < max+1; i++){
		count[i] = 0;
	}

	for(int i = 0; i < n; i++){
		count[arr[i]]++;
	}
	
	for(int i = 1; i < max+1; i++){
		count[i] += count[i-1];
	}

	int sortedArray[n];
	for(int i = n-1; i >=1; i--){
		sortedArray[--count[arr[i]]] = arr[i];
	}
	
	for(int i = 0; i < n; i++){
		arr[i] = sortedArray[i];
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	countSort(arr,n);
	
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

