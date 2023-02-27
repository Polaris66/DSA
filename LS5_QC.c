#include <stdio.h>

int checkFrequencyTable(int *ft, int k){
	int atLeastOne = 1;
	for(int i = 0; i < k; i++){
		if(ft[i]<1){
			atLeastOne = 0;
		}
	}
	return atLeastOne;
}

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int n, k;
	scanf("%d",&n);
	scanf("%d",&k);
	
	char s[n];
	scanf("%s",s);
	
	int ft[k];
	for(int i = 0; i < k; i++){
		ft[i] = 0;
	}
	int l = 0;
	int r = 0;
	ft[s[0]-97]+=1;
	int count = 0;
	while(){
		if(!checkFrequencyTable(ft,k)){
			
		}
		else{
		
		}
	}
	printArray(ft,k);
	printf("%d\n",count);
}

// 'a' = 97
