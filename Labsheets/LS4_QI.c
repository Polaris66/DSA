#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArray(int arr[], int n){
	
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}

int gcd(int a, int b){
	if(a>=b){
		int temp = a;
		a = b;
		b = temp;
	}
	if(a==1){
		return 1;
	}
	if(b%a==0){
		return a;
	}
	int g = gcd(a,(b%a));
	return g;
}

int main(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	int max_gcd = 0;
	int g = 0;
	for(int i = 0; i < n; i++){
		g = 0;
		for(int j = 0; j < n; j++){
			if(j!=i){
				if(g==0){
					g = arr[j];
				}
				else{
					g = gcd(arr[j],g);
				}
			}
		}
		if(g>max_gcd){
			max_gcd = g;
		}
	}
	printf("%d\n",max_gcd);
}
