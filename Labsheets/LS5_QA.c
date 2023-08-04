#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findNo(char s[], int n, int open, int index){
	static int count = 0;
	if(n==0){
		count++;
		return count;
	}
	if(open==0){
		s[index] = '(';
		findNo(s,n-1,open+1,index+1);
	}
	else{
		if(open==n){
			s[index] = ')';
			findNo(s,n-1,open-1,index+1);
		}
		else{
			s[index] = '(';
			findNo(s,n-1,open+1,index+1);
			
			s[index] = ')';
			findNo(s,n-1,open-1,index+1);
		}
	}
}

void printSequence(char s[], int n, int open, int index){
	if(n==0){
		for(int i = 0; i < index; i++){
			printf("%c",s[i]);
		}
		printf("\n");
		return;
	}
	if(open==0){
		s[index] = '(';
		printSequence(s,n-1,open+1,index+1);
	}
	else{
		if(open==n){
			s[index] = ')';
			printSequence(s,n-1,open-1,index+1);
		}
		else{
			s[index] = '(';
			printSequence(s,n-1,open+1,index+1);
			
			s[index] = ')';
			printSequence(s,n-1,open-1,index+1);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	char arr[n];
	for(int i = 0; i < n; i++){
		arr[i] = ' ';
	}
	int k = findNo(arr,n,0,0);
	printf("%d\n",k);
	printSequence(arr,n,0,0);
}
