#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);	
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	int ft[n];
	for(int i = 0; i < n; i++){
		ft[i] = 0; 
	}
	
	int j = 0;
	for(int i = 0; i < n; i++){
		ft[arr[i]] += 1;
		while(j<=i && ft[arr[j]]!=1){
			j++;
		}
		if(j>i){
			printf("-1 ");	
		}
		else{
			printf("%d ",arr[j]);
		}
	}
	printf("\n");
}
