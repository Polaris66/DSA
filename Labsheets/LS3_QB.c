#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t{
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
}

void addToList(Node *cur, int val){
	Node *temp = cur;
	Node *newNode = createNode(val);
	while((temp->next)!=NULL){
		temp = temp->next;
	}
	newNode->prev = temp;
	temp->next = newNode;
}

Node *findHead(Node *cur){
	Node *head = cur;
	while((head->prev)!=NULL){
		head = head->prev;
	}
	return head;
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

void printList(Node *cur){
	Node *temp = findHead(cur);
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printCurrent(Node *cur){
	printf("\n%d",cur->data);
}

void playNext(Node **cur){
	if((*cur)->next!=NULL){
		*cur = (*cur)->next;
	}
}
void playPrev(Node **cur){
	if((*cur)->prev!=NULL){
		*cur = (*cur)->prev;
	}
}

Node *findNode(Node *cur, int val){
	Node *temp = findHead(cur);
	while(temp!=NULL){
		if((temp->data) == val){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void putNext(Node *cur, int val){
	Node *target = findNode(cur,val);
	if(target==NULL){
		target = createNode(val);
	}
	else{
		Node *pre = target->prev;
		Node *nxt = target->next;
		if(pre!=NULL){
			pre->next = nxt;
		}
		if(nxt!=NULL){
			nxt->prev = pre;
		}
	}
	Node *curNext = cur->next;
	target->prev = cur;
	target->next = curNext;
	cur->next = target;
	if(curNext!=NULL){
		curNext->prev = target;
	}	
}

int main(){
	Node *cur = readList();
	int done = 0;
	while(!done){
		int x;
		scanf("%d",&x);
		int val;
		switch(x){
			case(1):
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
				scanf("%d",&val);
				putNext(cur,val);
				break;	
		}
	}
}
