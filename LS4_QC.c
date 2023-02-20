#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int arr[], int n){
	
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}

int countGoodPairs(int arr[], int n){
	
}

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	int newArray[n];
	for(int i = 0; i < n; i++){
		newArray[i] = arr[i] / 5;
	}
	printArray(arr,n);
}

/// No of zeros in trailing is min no of 5 powers, 
/// = [n/5^k] + ... [n/5]
/// which means for same values should be same multiple of 5
/// [n1/5] = [n2/5]

