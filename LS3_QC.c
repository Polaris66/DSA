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
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;	
}


Node *findHead(Node *cur){
	Node *head = cur;
	while((head->prev)!=NULL){
		head = head->prev;
	}
	return head;
}

Node *findEnd(Node *cur){
	Node *end = cur;
	while((end->next)!=NULL){
		end = end->next;
	}
	return end;
}

void addToList(Node *cur, int val){
	Node *end = findEnd(cur);
	Node *newNode = createNode(val);
	newNode->prev = end;
	end->next = newNode;
}


void printList(Node *cur){
	Node *temp = findHead(cur);
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Node *readList(){
	int n;
	scanf("%d",&n);
	Node *cur = NULL;
	while(n--){
		int val;
		scanf("%d",&val);
		if(cur==NULL){
			cur = createNode(val);
		}
		else{
			addToList(cur,val);
		}
	}
	return cur;
}

void checkDyadAggregate(Node *cur,int target){
	Node *a = findHead(cur);
	Node *b = findEnd(cur);
	int done = 0;
	while(!done){
		int x = a->data;
		int y = b->data;
		int sum = x+y;
		if(b==a){
			printf("0\n");
			return;
		}
		if(target==sum){
			printf("1\n");
			return;
		}
		if(target<sum){
			b = b->prev;
		}
		else{
			a = a->next;
		}
	}
}

int main(){
	int target;
	scanf("%d",&target);
	Node *cur = readList();
	checkDyadAggregate(cur,target);
}
