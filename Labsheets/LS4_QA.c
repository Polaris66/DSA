#include <stdio.h>

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	
	int first[n];
	int second[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&first[i]);
		scanf("%d",&second[i]);
	}	
}

