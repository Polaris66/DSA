#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void shift_right(int *arr, int target, int i){
	int val = arr[i];
	int t1 = arr[target];
	int t2 = 0;
	for(int j = target+1; j <=i; j++){
		t2 = arr[j];
		arr[j] = t1;
		t1 = t2;
	}
	arr[target] = val;
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int target = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < n; i++){
		if(arr[i]<0){
			shift_right(arr,target,i);
			target += 1;
		}	
	}
	print(arr,n);
}
