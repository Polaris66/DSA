#include <stdio.h>

		


int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	int A[m][n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&(A[i][j]));
		}
	}
	int B[m][n];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			B[i][j] = 0;
			int *ptr = &(A[0][0]);
			int diff = n*i+j;
			for(int i_n = 0; i_n <=diff; i_n++){
				B[i][j]+=*(*A+i_n);
			}
		}
	}
	for(int i = 0; i < m; i++){
		printf("\n");
		for(int j = 0; j < n; j++){
			printf("%d ",B[i][j]);
		}
		
	}
}
