#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
} node;

node *create(int val){
	node *ptr = (node *) malloc(sizeof(node));
	ptr->val = val;
	ptr->next=NULL;
	return ptr;
}

void add(node **head, int val){
	node *ptr = create(val);
	if((*head)==NULL){
		*head = ptr;
		return;
	}
	node *temp = *head;
	while((temp->next)!=NULL){
		temp = temp->next;
	}
	temp->next = ptr;
}

void traverse(node *head){
	while(head!=NULL){
	printf("%d\n",head->val);
	head = head->next;
	}
}

void reverse(node **head)
{
	if((*head)==NULL || (*head)->next == NULL){
	return;
	}
	node *previous = *head;
	node *current = (*head)->next;
	while(current!=NULL){
		node *next = current->next; // save the nextNode because we are gonna cut the connection
		current->next = previous;//change the connection
		previous = current;//update previous, because current will be changed
		current = next;//current is changed
	}
	(*head)->next = NULL;//only head is left
	*head = previous;
}

int main(){
	node* head = create(1);
	add(&head,2);
	add(&head,3);
	add(&head,4);
	add(&head,5);
	reverse(&head);
	traverse(head);
}
