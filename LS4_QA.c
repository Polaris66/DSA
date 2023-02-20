#include <stdio.h>

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	int start[n];
	int end[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&start[i]);
		scanf("%d",&end[i]);
	}
}

