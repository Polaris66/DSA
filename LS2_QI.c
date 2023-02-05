#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Student_t {
	 char email[1000];
	 char branchName[1000];
	 char id[1000];
} Student; 

Student *read(){
	Student *s = (Student *) malloc(sizeof(Student));
	assert(s!=NULL);
	char email[1000];
	char branchName[1000];
	fgets(email,sizeof(email),stdin);
	fgets(branchName,sizeof(branchName),stdin);
	for(int i = 0; i < strlen(email)-1; i++){
		s->email[i] = email[i];
	}
	for(int i = 0; i < strlen(branchName)-1; i++){
		s->branchName[i] = branchName[i];
	}
	return s;
}

void print(Student *s){
	puts(s->email);
	puts(s->branchName);
	puts(s->id);	
}

void generateId(Student **s){
	char id[1000];
	char *email = (*s)->email;
	char *branchName = (*s)->branchName;
	for(int i = 0; i < 4; i++){
		id[i] = email[i+1];
	}
	id[4] = 'A';
	if(branchName[0]=='C'){
		id[5] = '7';	
	}
	else if(branchName[1] == 'C'){
		id[5] = 'A';
	}
	else{
		id[5] = '3';	
	}
	id[6] = 'P';
	id[7] = 'S';
	for(int i = 0; i < 4; i++){
		id[i+8] = email[i+5];
	}
	id[12] = 'H';
	id[13] = '\0';
	for(int i = 0; i < strlen(id); i++){
		(*s)->id[i] = id[i];
	}	
}

int main(){
	Student *s = read();
	//print(s);
	generateId(&s);
	puts(s->id);
}
