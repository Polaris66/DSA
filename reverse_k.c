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

void addToList(Node *head, int val){
	Node *newNode = createNode(val);
	Node *temp = head;
	while((temp->next)!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void printList(Node *head){
	Node *temp = head;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Node *readList(){
	int n;
	scanf("%d",&n);
	
	Node *head = NULL;
	while(n--){
		int val;
		scanf("%d",&val);
		if(head==NULL){
			head = createNode(val);
		}
		else{
			addToList(head,val);
		}
	}
	return head;
}

int countNodes(Node *head){
	Node *temp = head;
	int count = 0;
	
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

Node *reverse_k(Node *begin, int k){
	Node *prev = begin;
	Node *curr = begin->next;
	k--;
	while(k--){
		Node *next = curr->next;
		
		curr->next = prev;
		
		prev = curr;
		curr = next;
	}
	begin->next = curr;
	return prev;
}

int main(){
	Node *head = readList();
	printList(head);
	int k;
	scanf("%d",&k);
	int n = countNodes(head);
	int times = n/k;
	k--;
	Node *begin = head;
	Node *prev_prev = NULL;
	for(int i = 0; i < times; i++){
		Node *prev = begin;
		Node *curr = begin->next;
		for(int j = 0; j < k; j++){
			Node *next = curr->next;
			curr->next = prev;
			
			prev = curr;
			curr = next;
		}		
		begin->next = curr;
		begin = curr;
		prev_prev = prev;
		if(i==0){
			head = prev;
		}
		printList(head);			
	}
	
}

