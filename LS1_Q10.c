#include <stdio.h>
#include <string.h>

void print(int *arr, int n){
	for(int i = 0; i < n; i++){
	printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	char s[1000];
	char a[1000];
	scanf("%s",s);
	scanf("%s",a);
	int n = strlen(a);
	int ans[n];
	char c;
	int found;
	int possible = 1;
	for(int i = 0; i < n; i++){
		c = a[i];
		found = 0;
		for(int j = 0; j < n; j++){
			if(s[j]==c){
				found = 1;
				s[j] = '.';
				ans[i] = j+1;
				break;
			}
		}
		if(found==0){
			printf("NOT POSSIBLE");
			possible = 0;
			break;
		} 
	}
	if(possible){
	for(int i = 0; i < n; i++){
		printf("%d ",ans[i]);
	}
	}
}
