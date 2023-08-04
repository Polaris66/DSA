#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void copy(char *a, char *b){
	for(int i = 0; i < 1000; i++){
		if(b[i] != '\n'){
			a[i] = b[i];
		} 
	}
}

bool compare(char *a, char *b){
	bool same = true;
	for(int i = 0; i < strlen(a); i++){
		if(a[i]!=b[i]){
			same = false;
		}
	}
	return same;
}

void reverse(char *a){
	for(int i = 0; i < strlen(a)/2; i++){
		char temp = a[i];
		a[i] = a[strlen(a)-i-1];
		a[strlen(a)-i-1] = temp; 
	}
	return;
}

int main(){
	char input[1000];
	fgets(input,1000,stdin);
	char s[1000];
	copy(s,input);
	char *token = strtok(s," ");
	while(token){
		char temp[1000];
		copy(temp,token);
		reverse(temp);
		printf("%s ",temp);
		token = strtok(NULL," ");
	}
	printf("\n");
	char *token1 = strtok(s," ");
	while(token1){
		char temp[1000];
		copy(temp,token);
		char r[1000];
		copy(r,temp);
		reverse(r);
		if(compare(r,temp) && strlen(temp)!=1){
			printf("%s ",temp);
		}
		token1 = strtok(NULL," ");
	}
}
