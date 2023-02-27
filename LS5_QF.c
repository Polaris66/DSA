#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int A[n]; 
	for(int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	
	int m;
	scanf("%d",&m);
	int B[m]; 
	for(int i = 0; i < m; i++){
		scanf("%d",&B[i]);
	}
	
	int ans = A[0];
	for(int i = 1; i < n; i++){
		ans = ans^(A[i]);
	}
	for(int i = 0; i < m; i++){
		ans = ans^(B[i]);
	}
	printf("%d\n",ans);
}
