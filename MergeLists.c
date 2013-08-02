#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node * List;

List newList(int data){
	List temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

List merge(List l1, List l2){
	List head = NULL, curr=head, temp=NULL;
	while(l1 && l2){
		if(l1->data < l2->data){
			if(!head){
				printf("case 1, ");
				curr = head = l1;
				l1 = l1->next;
			}else if(curr->next != l1){
				printf("case 2, ");
				temp = l1;
				l1 = l1->next;
				temp->next = curr->next;
				curr->next = temp;
				curr = curr->next;
			}else{
				printf("case 3, ");
				l1 = l1->next;
				curr = curr->next;
			}
		}else{
			if(!head){
				printf("case 4, ");
				curr = head = l2;
				l2 = l2->next;
			}else if(curr->next != l2){
				printf("case 5, ");
				temp = l2;
				l2 = l2->next;
				temp->next = curr->next;
				curr->next = temp;
				curr = curr->next;
			}else{
				printf("case 6, ");
				l2 = l2->next;
				curr = curr->next;
			}
		}
		if(l2->next == l2)
		printf("error");
	}
	if(l1)
		curr->next = l1;
	while(curr->next)
		curr = curr->next;
	if(l2)
		curr->next = l2;
	return head;
}

int main(){
	List l1 = newList(5);
	l1->next = newList(6);
	l1->next->next = newList(9);
	l1->next->next->next = newList(10);
	
	List l2 = newList(4);
	l2->next = newList(7);
	l2->next->next = newList(8);
	l2->next->next->next = newList(11);
	
	List output = merge(l1,l2);
	printf("\n");
	for(;output; output = output->next)
		printf("%d ",output->data); 
	return 0;
}