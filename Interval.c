#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
#define max(a,b)	((a>b) ? (a) : (b))

struct node{
	int start;
	int end;
	int maxEnd;
	struct node *left;
	struct node *right;
};

typedef struct node * Node;

Node newNode(int start, int end, int maxEnd){
	Node temp = malloc(sizeof(struct node));
	temp->start = start;
	temp->end = end;
	temp->maxEnd = max(maxEnd,temp->end);
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(Node *root, int start, int end){
	if(!*root){
		*root = newNode(start,end,end);
		return;
	}
	(*root)->maxEnd = max((*root)->maxEnd,end); 
	if((*root)->start < start)
		insert(&((*root)->left),start, end);
	else
		insert(&((*root)->right), start, end);
}

int isInter(Node root, int start, int end){
	if(!root)
		return false;
	else if( (start >= root->start && start <= root->end ) || (end >= root->start && end <= root->end) )
		return true;
	else if(!root->left)
		return isInter(root->right, start, end);
	else if(root->left->maxEnd < start)
		return isInter(root->right, start, end);
	else
		return isInter(root->left, start, end);
}

int main(){
	Node root = NULL;
	int n,s,e,i=0;
	int a[2][6] = {	{4,5,7,15,17,21},	{8,8,10,18,19,24}	};	
//	printf("Enter no of Intervals to put : ");
//	scanf("%d",&n);
	n = 6;
	while(i<n){
//		scanf("%d %d",&s,&e);
//		insert(&root,s,e);
		insert(&root,a[0][i],a[1][i]);
		i++;
	}
	printf("\nEnter no of Intervals to check : ");
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&s,&e);
		printf("Intersects : %d\n",isInter(root,s,e));
	}
	return 0;
}