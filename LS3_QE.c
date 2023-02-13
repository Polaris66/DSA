#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t {
	int data;
	struct Node_t *prev;
	struct Node_t *next;
} Node;

Node *createNode(int val){
	Node *newNode = (Node *) malloc(sizeof(Node));
	assert(newNode!=NULL);
	
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

Node *findHead(Node *cur){
	Node *head = cur;
	
	while((head->prev)!=NULL){
		head = head -> prev;
	}
	
	return head;
}

Node *findEnd(Node *cur){
	Node *end = cur;
	
	while((end->next)!=NULL){
		end = end -> next;
	}
	
	return end;
}

void addToList(Node *cur, int val){
	Node *end = findEnd(cur);
	
	Node *newNode = createNode(val);
	
	newNode->prev = end;
	end->next = newNode;
}

void rotateList(Node *cur){
	Node *head = findHead(cur);
	Node *end = findEnd(cur);
	Node *prevOfEnd = end->prev;
	prevOfEnd->next = NULL;
	end->prev = NULL;
	end->next = head;
	head->prev = end;
}

void printList(Node *cur){
	Node *temp = findHead(cur);
	
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	
	printf("\n");
}

int main(){
	int n, k;
	scanf("%d",&n);
	scanf("%d",&k);
	Node *cur = NULL;
	while(n--){
		int val;
		scanf("%d",&val);
		if(cur == NULL){
			cur = createNode(val);
		}
		else{
			addToList(cur,val);
		}
	}
	while(k--){
		rotateList(cur);
	}
	printList(cur);	
}
