#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node_t {
	long int data;
	struct Node_t *prev;
	struct Node_t *next;
} Node;

Node *createNode(long int val){
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
void addToList(Node *cur, long int val){
	Node *newNode = createNode(val);
	
	Node *end = findEnd(cur);
	
	newNode->prev = end;
	end->next = newNode;
}

void printList(Node *cur){
	Node *temp = findHead(cur);
	
	while(temp!=NULL){
		printf("%ld ",temp->data);
		temp = temp->next;
	}
	
	printf("\n");
}

Node *readList(){
	long int n;
	scanf("%ld",&n);
	
	Node *cur = NULL;
	
	while(n--){
		long int val;
		scanf("%ld",&val);
		
		if(cur==NULL){
			cur = createNode(val);
		}
		else{
			addToList(cur,val);
		}
	}
	return cur;
}

void findTwoTeams(Node *cur){
	long int l_sum, r_sum, max_l_sum, max_r_sum, l_count, r_count, max_l_count, max_r_count;
	l_sum = 0;
	r_sum = 0;
	l_count = 0;
	r_count = 0;
	max_l_count = 0;
	max_r_count = 0;

	Node *l = findHead(cur);
	Node *r = findEnd(cur);
	l_sum+=l->data;
	r_sum+=r->data;
	while(1){
		if(l==r){
			break;
		}
		long int x = l->data;
		long int y = r->data;
		
		if(l_sum>r_sum){
			 r = r->prev;
			 r_sum+=r->data;
			 r_count+=1; 
		}
		else if(l_sum<r_sum){
			l = l->next;
			l_sum+=l->data;
			l_count+=1;
		}
		else{
			max_l_count = l_count;
			max_r_count = r_count;
			l = l->next;
			l_sum+=l->data;
			l_count+=1;
		}
	}
	max_l_count+=1;
	max_r_count+=1;
	printf("%ld %ld\n",max_l_count,max_r_count);
}

int main(){
	Node *cur = readList();
	//printList(cur);
	findTwoTeams(cur);
}
