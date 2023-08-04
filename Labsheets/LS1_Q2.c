#include <stdio.h>

void print(int* arr,int m,int n){
	for(int i = 0; i < m; i++){
		printf("\n");
		for(int j = 0; j < n; j++){
			printf("%d ",arr[i*n+j]);
		}
	}
	printf("\n\n");
}

int find(int* arr, int m, int n, int val){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(val==(arr[i*n+j])){
			return (i*n+j);
			}
		}
	}
	return -1;
}

int main(){
	int m, n;
	scanf("%d%d",&m,&n);
	int A[m][n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&A[i][j]);
		}
	}
	int p, q;
	scanf("%d%d",&p,&q);
	int B[p][q];
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			scanf("%d",&B[i][j]);
		}
	}
	//print(*A,m,n);
	//print(*B,p,q);
	
	//TODO:Algorithm
	int full = 0;
	int first_element = find(*A,m,n,B[0][0]);
	if(first_element!=-1){
		full = 1;
		int x0 = first_element/n;
		int y0 = first_element%n;
		for(int i = 0; i < p; i++){
			for(int j = 0; j < q; j++){
				if(B[i][j]!=A[x0+i][y0+j]){
					full = 0;
				}				
			}
		}
		if(full){
		printf("YES\n");
		}
	}
	
	if(!full){
		int partial = 0;
		//rows
		for(int i = 0; i < p; i++){
			first_element = find(*A,m,n,B[i][0]);
			if(first_element!=-1){
			int x0 = first_element/n;
			int y0 = first_element%n;
			partial = 1;
			for(int j = 0; j < q; j++){
				if(B[i][j]!=A[x0+i][y0+j]){
					partial = 0;
				}
			}
			}
			if(partial){
				printf("PARTIAL\n");
				break;
			}			
		}
		//colums
		if(!partial){
		for(int j = 0; j < q; j++){
			first_element = find(*A,m,n,B[0][j]);
			if(first_element!=-1){
			int x0 = first_element/n;
			int y0 = first_element%n;
			partial = 1;
			for(int i = 0; i < p; i++){
				if(B[i][j]!=A[x0+i][y0+j]){
					partial = 0;
				}
			}
			}
			if(partial){
				printf("PARTIAL\n");
				break;
			}			
		}
		}
		if(!partial){
			printf("NO\n");
		}		
	}	
	
}
