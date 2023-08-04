#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i <  n; i++){
		scanf("%d",&arr[i]);
	}
	int s;
	scanf("%d",&s);
}

