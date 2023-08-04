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
	int max = 0;
	for(int i = 0; i < n; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	max/=5;
	int newArray[n];
	for(int i = 0; i < n; i++){
		newArray[i] = arr[i] / 5;
	}
	int ft[max+1];
	for(int i = 0; i < max+1; i++){
		ft[i] = 0;
	}
	for(int i = 0; i < n; i++){
		ft[newArray[i]]+=1;
	}
	
	int ans = 0;
	for(int i = 0; i < max+1; i++){
		ans+=(ft[i]*(ft[i]-1)/2);
	}
	printf("%d\n",ans);
}

/// No of zeros in trailing is min no of 5 powers, 
/// = [n/5^k] + ... [n/5]
/// which means for same values should be same multiple of 5
/// [n1/5] = [n2/5]

