#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t {
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

Node *addToList(Node *head, int val){
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

void printList(Node *head){
	Node *cur = head;
	while(cur!=NULL){
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
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

int countNodes(Node *head){
	Node *cur = head;
	int count = 0;
	while(cur!=NULL){
		count++;
		cur = cur->next;
	}
	return count;
}

int isPalindrome(Node *head){
	Node *a = head;
	int n = countNodes(head);
	for(int i = 0; i < n/2; i++){
		Node *b = head;
		for(int j = 0; j < n - i - 1; j++){
			b = b->next;
		}
		if((a->data)!=(b->data)){
			return 0;
		}
		a = a->next; 
	}
	
	return 1;
}

int main(){
	Node *head = readList();
	int palin = isPalindrome(head);
	printf("%d\n",palin);
	//printList(head);
	freeList(head);	
}
