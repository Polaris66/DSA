#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t{
	int data;
	struct Node_t *next;
} Node;

Node *createNode(int val){
	Node *newNode = (Node *) malloc(sizeof(Node));
	assert(newNode!=NULL);
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

Node *addToList(Node *head,int val){
	Node *newNode = createNode(val);
	if(head==NULL){
		return newNode;
	}
	
	Node *cur = head;
	while((cur->next)!=NULL){
		cur = cur->next;
	}
	cur->next = newNode;
	return newNode;
}

void freeList(Node *head){
	Node *cur, *nxt;
	cur = head;
	while(cur!=NULL){
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}

void printList(Node *head){
	Node *cur = head;
	while(cur!=NULL){
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

Node *readList(){
	int n;
	scanf("%d",&n);
	
	Node *head = NULL;
	
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d",&val);
		if(head==NULL){
			head = addToList(head,val);
		}
		else{
			addToList(head,val);
		}
	}
	return head;
	}
	
Node *reverseList(Node *head){
	if(head==NULL || (head->next)==NULL){
		return head;
	}
	Node *prev = head;
	Node *cur = head->next;
	
	while(cur!=NULL){
		Node *nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;		
	}
	head->next = NULL;
	return prev; 
}
int main(){
	Node *head = readList();
	head = reverseList(head);
	printList(head);
	freeList(head);
}
