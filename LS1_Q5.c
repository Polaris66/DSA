#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int val = 2;
	int x = n/2;
	int y = (n-1)/2;
	int dir = 0;
	int dir_change = 0;
	for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
		arr[i][j] = 0;
	}
	}
	
	for(int i = 1; i <= n*n; i++){
		arr[x][y] = 2*i;
		
		if(dir==0){
			y+=1;
		}
		else if(dir==1){
			x-=1;
		}	
		else if(dir==2){
			y-=1;
		}
		else if(dir==3){
			x+=1;
		}
	}
	
	for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
		printf("%d ",arr[i][j]);
	}
	printf("\n");
	}
}
