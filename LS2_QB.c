#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t {
	int data;
	struct Node_t *next;
} Node;

Node *createNode(int val){
	Node *newNode = malloc(sizeof(Node));
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
	else{
		Node *cur = head;
		while((cur->next)!=NULL){
			cur = cur->next;
		}
		cur->next = newNode;
		return newNode;	
	}
}

Node *readList(){
	int n;
	scanf("%d", &n);
	
	Node *head = NULL;
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
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

int countNodes(Node *head){
	int count = 0;
	Node *cur = head;
	while(cur!=NULL){
		count++;
		cur = cur -> next;
	}
	return count;
}

Node *mergeLists(Node *head1, Node *head2){
	
	//base case
	
	if(head1==NULL){
		return head2;
	}
	else if(head2 == NULL){
		return head1;
	}
	Node *merged = NULL;
	
	if((head1->data)<=(head2->data)){
		merged = head1;
		merged->next = mergeLists(head1->next,head2);
	}
	else{
		merged = head2;
		merged->next = mergeLists(head1,head2->next);
	}
	
	return merged;
}

int main(void){	
	Node *head1 = readList();
	Node *head2 = readList();
	Node *merged = mergeLists(head1, head2);
	printList(merged);
	freeList(merged);	
	return 0;
}
