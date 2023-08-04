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

Node *removeRepeatedNodes(Node *head){
	Node *cur = head;
	while(cur!=NULL){
		if(cur->next==NULL || (cur->next->next)==NULL){
			break;
		}
		if(((cur->next)->data) == ((cur->next->next)->data)){
			int val = cur->next->data;
			Node *target = cur->next;
			while(target->data == val){
				target = target->next;
			}
			cur->next = target;
		}
		else{
			cur = cur->next;
		}
	}
	return head;
	}
	
int main(){
	Node *head = readList();
	head = removeRepeatedNodes(head);
	printList(head);
	freeList(head);
}
