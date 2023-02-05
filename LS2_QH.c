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
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void freeList(Node *head){
	Node *cur = head;
	while(cur!=NULL){
		Node *nxt = cur->next;
		free(cur);
		cur = nxt;
	}
}

int countNodes(Node *head){
	int count = 0;
	Node *cur = head;
	while(cur!=NULL){
		count++;
		cur = cur->next;
	}
	return count;
}

Node *removeSlide(Node *head, int k){
	int n = countNodes(head);
	if(k==n){
		return head->next;
	}
	Node *cur = head;
	for(int i = 0; i < (n-k-1); i++){
		cur = cur->next;
	}
	Node *temp = (cur->next)->next;
	cur->next = temp;
	return head;
}
int main(){
	int k;
	scanf("%d", &k);
	Node *head = readList();
	head = removeSlide(head, k);
	printList(head);
	freeList(head);
}
