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
	newNode->next=NULL;
	return newNode;
}

Node *addToList(Node *head, int val){
	Node *newNode = createNode(val);
	if(head==NULL){
		return newNode;
	}
	Node *cur = head;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode;
	return newNode;
}

Node *readList(){
	int n;
	scanf("%d", &n);
	
	Node *head = NULL;
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(head == NULL){
			head = addToList(head,x);
		}
		else{
			addToList(head,x);		
		}
	}
	
	return head;
}

void printList(Node *head){
	Node *cur = head;
	while(cur!=NULL){
		printf("%d ", cur->data);
		cur = cur -> next;
	}
	printf("\n");
	return;
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

int noOfNodes(Node *head){
	Node *curr = head;
	int count = 0;
	while(curr!=NULL){
		count+=1;
		curr = curr -> next;
	}
	return count; 
}

int findMedian(Node *head){
	int n = noOfNodes(head);
	if((n%2)==1){
		Node *curr = head;
		for(int i = 1; i < (n+1)/2; i++){
			curr = curr->next;	
		}
		return curr->data;
	}
	else{
		Node *curr = head;
		for(int i = 1; i < (n)/2; i++){
			curr = curr->next;	
		}
		return (curr->data+curr->next->data)/2;
	}
}

int main(void){
	Node *head = readList();
	int median = findMedian(head);
	printf("%d\n", median);
	freeList(head);		
	return 0;
}
