#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} Node;


void printList(Node *cur){
	Node *temp = cur;
	while(cur!=NULL){
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

Node *createNode(int val){
	Node *newNode = (Node *) malloc(sizeof(Node));
	assert(newNode!=NULL);
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

Node *addToList(Node *cur, int val){
	Node *newNode = createNode(val);
	if(cur==NULL){
		return newNode;
	}
	Node *temp = cur;
	while((temp->next) != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	return newNode;
}

Node *readList(){
	int n;
	scanf("%d",&n);
	Node *cur = NULL;
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d",&val);
		if(cur==NULL){
			cur = addToList(cur,val);
		}
		else{
			addToList(cur,val);
		}
	}
	return cur;
}

void printCurrent(Node *cur){
	printf("%d\n",cur->data);
}

void playNext(Node **cur){
	if((*cur)->next==NULL){
		return;
	}
	*cur = (*cur)->next;
}

void playPrev(Node **cur){
	if((*cur)->prev==NULL){
		return;
	}
	*cur = (*cur)->prev;
}

Node *findHead(Node *cur){
	Node *temp = cur;
	while((temp->prev)!=NULL){
		temp = temp->prev;
	}
	return temp;
}

Node *findNode(Node *cur, int val){
	Node *head = findHead(cur);
	Node *temp = head;
	while(temp!=NULL){
		if((temp)->data == val){
			return temp;
		} 
		temp = temp->next;
	}
	return NULL;
}
Node *addToQueue(Node *cur, int val){
	Node *temp = findNode(cur,val);
	if(temp==NULL){
		temp = createNode(val);
		temp->next = cur->next;
		temp->prev = cur;
		(cur->next)->prev = temp;
		cur->next = temp;
	}
	else{	
		if((temp->prev)!=NULL)
		{
			(temp->prev)->next = temp->next;
			printf("HI");
		}
		if((temp->next)!=NULL){
		(temp->next)->prev = temp->prev;}
		temp->prev = cur;
		temp->next = cur->next;
		if((cur->next)!=NULL)
		{(cur->next)->prev = temp;}
		cur->next = temp;	
	}
	return cur;
}

int main(){
	Node *cur = readList();
	int operation;
	int done = 0;

	while(!done){
		scanf("%d",&operation);
		switch(operation){
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
			case(6):
				val;
				scanf("%d",&val);
				cur = addToQueue(cur,val);	
				break;
		}	
	}			
}
