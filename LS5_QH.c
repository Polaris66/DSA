#include <stdio.h>

void printArray(int arr[], int n){
	for(int i =0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int n, k;
	scanf("%d",&n);
	scanf("%d",&k);
	int arr[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	int prefix[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum+=arr[i];
		prefix[i] = sum;
	}
	
	for(int i = 0; i < n; i++){
		prefix[i] = prefix[i]%k;
	}	
	
	int ft[k];
	
	for(int i = 0; i < k; i++){
		ft[k] = 0;
	}
	for(int i = 0; i < n; i++){
		ft[prefix[i]]++;
	}
	int ans = 0;
	for(int i = 0; i < k; i++){
		if(ft[i]>1){
			ans+=(ft[i])*(ft[i]-1)/2;
		}
	}
	ans+=ft[0];
	printf("%d\n",ans);
}
