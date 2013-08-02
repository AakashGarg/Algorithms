#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
typedef struct node* Node;

Node newNode(int e){
	Node n = malloc(sizeof(struct node));
	n->data = e;
	n->link = NULL;
	return n;
}

void insert(int e, Node *list){
	Node n;
	n = *list;
	if(n==NULL){
		(*list) = newNode(e);
		return;
	}
	while(n->link)
		n = n->link;
	n->link = (Node) newNode(e);
}
//Recursive reverse
Node recReverse(Node curr, Node prev){
	if(curr==NULL)		return prev;
	Node next = curr->link;
	curr->link = prev;
	return(next,curr);
}

//Iterative reverse
void reverse(Node *list){
	Node prev,curr,next;
	prev = NULL;
	curr = *list;
	if(!curr || !(curr->link))		return;
	while(curr){
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	*list = prev;
}

void printList(Node list){
	while(list){
		printf("%d-->",list->data);
		list = list->link;
	}
}

int main(){
	int n,e;
	Node list = NULL;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&e);
		insert(e,&list);
	}
	printf("\nList data : ");
	printList(list);
	printf("\nReverse of list : ");
	list = recReverse(list,NULL);
	printList(list);
}