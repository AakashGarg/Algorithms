//Stack implementation using LinkedList approach LIFO disceplene
#include<stdio.h>
#include<stdlib.h>

struct node {
	int a;
	struct node *prev;
};

struct node *top;
struct node *bottom;

//	METHOD TO PUSH ELEMENT INTO STACK
void push(int e){
	struct node *p = (struct node*) malloc(sizeof(struct node));
	p->a = e;
	if((top==0) || (bottom==0)){
		p->prev = 0;
		top = bottom = p;
	}
	else{
		p->prev = top;
		top = p;
	}
}

//	METHOD TO POP ELEMENT FROM STACK
int pop(){
	if((top==0) || (bottom==0)){
		printf("stack underflow\n");
		return 0;
	}
	else{
		int e = top->a;
		struct node *ptr = top;
		top = top->prev;
		free(ptr);
		printf("popped = %d\n",e);
		return e;
	}
}

//	METHOD TO DELETE STACK COMPLETELY
void delete(){
	//deleting a stack is popping out every element
	struct node *p = top;
	while(p!=0){
		p = p->prev;
		pop();
	}
}

//	METHOD TO PRINT CONTENTS OF STACK
void printData(){
	if((top==0) || (bottom==0)){
		printf("stack empty\n");
		return;
	}
	printf("Stack Data : \n");
	struct node *p = top;
	while(p!=0){
		printf(" %d\n",p->a);
		p = p->prev;
	}
	printf("\n");
}

//	TODO LOGIC HERE
int main(){
	//initializing top and bottom to null
	top = (struct node*) malloc(sizeof(struct node));
	top = 0;
	bottom = (struct node*) malloc(sizeof(struct node));
	bottom = 0;

	char input = '1';
	int e = 0;
	
	printf("\nUse '+ e' to push");
	printf("\nUse '-' to pop");
	printf("\nUse '.' to delete Stack\n\n");
	
	while(input!='.'){
		printf("Input : ");
		scanf("%c",&input);
		if(input == '+'){
			scanf("%d",&e);
			push(e);
			printData();
		}
		else if(input == '-'){
			pop();
			printData();
		}
		else if(input == '.'){
			delete();
		}
		else{
			printData();
			printf("bye");
			break;
		}
		scanf("%c",&input);
	}
	
return 0;
}