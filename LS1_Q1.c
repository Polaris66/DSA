#include <stdio.h>
#include <stdlib.h>

void print(int **mat,int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j<n; j++){
			printf("%d ",mat[i][j]);		
		}
		printf("\n");
	}
}

int main(){
	int m, n;
	scanf("%d %d",&m,&n);
	int **A =(int **) malloc(sizeof(int *)*m); 
	for(int i = 0; i < m; i++){
		int *row = malloc(sizeof(int)*n);
		(A)[i] = row;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&(A[i][j]));
		}
	}
	int **B =(int **) malloc(sizeof(int *)*m); 
	for(int i = 0; i < m; i++){
		int *row = malloc(sizeof(int)*n);
		(B)[i] = row;
	}
	
	for(int i = 0; i < m; i++){
	for(int j = 0; j < n; j++){
		B[i][j] = 0;
		for(int i_1 = 0; i_1 < i; i_1++){
		for(int j_1 = 0; j_1<=n; j_1++){
		B[i][j]+=A[i_1][j_1];
		}
		}
		for(int j_1 = 0; j_1<=j; j_1++){
		B[i][j]+=A[i][j_1];
		}
	}
	}
	int ri, ci, rh, ch;
	scanf("%d%d%d%d",&ri,&ci,&rh,&ch);
	
	//check condition	
	print(B,m,n);
	if((ri+rh)>(m) || (ci+ch)>(n)){
		printf("NOT POSSIBLE\n");
	}
	else{
		int sum = 0;
		for(int i = ri; i < (ri+rh);i++){
		for(int j = ci; j < (ci+ch);j++){
			sum+=B[i][j];
		}
		}
		printf("%d\n",sum);
	}
}

