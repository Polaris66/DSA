#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(long long int arr[], long long int n){
	for(int i = 0; i < n; i++){
		printf("%lld ", arr[i]);
	}
	printf("\n");
}


int main(){
	long long int n;
	scanf("%lld",&n);

	long long int arr[n];
	for(long long int i = 0; i < n; i++){
		scanf("%lld",&arr[i]);
	}
	
	for(long long int i = 0; i < n-1; i ++){
		for(long long int j = 0; j < n-i-1; j ++){
			if(arr[j]>arr[j+1]){
				long long int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	long long int l = 0;
	long long int r = n-1;
	long long int operations = 0;
	while(l<r){
		operations+=(arr[r] - arr[l]);
		l++;
		r--;
	}
	printf("%lld\n",operations);
}

//Use median not mean
