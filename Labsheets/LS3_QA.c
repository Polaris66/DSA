#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *createNode(int val){
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = val;
	newNode->prev = NULL;
	newNode->next = NULL;
}

void addToList(Node *cur, int val){
	Node *newNode = createNode(val);
	Node *temp = cur;
	while((temp->next)!=NULL){
		temp = temp->next;
	}
	newNode->prev = temp;
	temp->next = newNode;
}

void printList(Node *cur){
	Node *temp = cur;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Node *readList(){
	int n;
	scanf("%d",&n);
	Node *cur = NULL;
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		if(cur==NULL){
			cur = createNode(val);
		}
		else{
			addToList(cur,val);
		}
	}
	return cur;
}

void printCurrent(Node *cur){
	if(cur!=NULL){
		printf("\n%d",cur->data);
	}
}

void playNext(Node **cur){
	if((*cur)!=NULL && ((*cur)->next)!=NULL){
		*cur = ((*cur)->next);
	}
}

void playPrev(Node **cur){
	if((*cur)!=NULL && ((*cur)->prev)!=NULL){
		*cur = ((*cur)->prev);
	}
}

int main(){
	Node *cur = readList();
	int done = 0;
	while(!done){
		int x;
		scanf("%d",&x);
		switch(x){
			case(1):
				int val;
				scanf("%d",&val);
				addToList(cur,val);
				break;
			case(2):
				printCurrent(cur);
				break;
			case(3):
				playNext(&cur);
				break;
			case(4):
				playPrev(&cur);
				break;
			case(5):
				done = 1;
				break;
		}
	}
}
