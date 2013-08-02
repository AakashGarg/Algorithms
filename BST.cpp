//	BINARY SEARCH TREE(BST) IMPLEMENTATION USING POINTERS
#include<stdio.h>
#include<stdlib.h>
#include<sys/queue.h>
#define TRUE 1
#define FALSE 0
#define max(a,b) (a>b ? a : b)
#define LEFT -1
#define RIGHT +1

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root;

//	METHOD TO INSERT ELEMENT INTO A BST
void insert(int e){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = e;
	temp->left = NULL;
	temp->right = NULL;
	
	if(root==NULL)		root = temp;
	else{
		struct node *ptr = root;
		while(ptr!=NULL){
			if(e < (ptr->data)){
				if(ptr->left==NULL){
					ptr->left = temp;
					break;
				}
				ptr = ptr->left;
			}
			else{
				if(ptr->right==NULL){
					ptr->right = temp;
					break;
				}
				ptr = ptr->right;
			}
		}
	}
}

//	METHOD TO SEARCH AN ELEMENT IN BST AND RETURNS THE CORRESPONDING NODE
struct node * find(int e){
	struct node *ptr = root;
	while(ptr!=NULL && ptr->data!=e){
		if(e < ptr->data){
			ptr = ptr->left;
		}else{
			ptr = ptr->right;
		}
	}
	if(ptr==NULL){
		printf("Element not found!\n");
		return NULL;
	}
	printf("Element found %d\n",ptr->data);
	return ptr;
}

//	METHOS TO DELETE AN ELEMENT FROM A BST
void delete(int e){
	struct node *ptr = root;
	struct node *prev = root;
	int dir = 0;
	while(ptr!=NULL && ptr->data!=e){
		prev = ptr;
		if(e < ptr->data){
			ptr = ptr->left;
			dir = LEFT;
		}else{
			ptr = ptr->right;
			dir = RIGHT;
		}
	}
	if(ptr==NULL)			return;
	else if(ptr->left==NULL && ptr->right!=NULL){
		if(dir==LEFT)		prev->left = ptr->right;
		else				prev->right = ptr->right;
		free(ptr);
	}else if(ptr->left!=NULL && ptr->right==NULL){
		if(dir==LEFT)		prev->left = ptr->left;
		else				prev->right = ptr->left;
		free(ptr);
	}else if(ptr->left!=NULL && ptr->right!=NULL){
		//	FINDING THE PREDECESSOR OF 'e'
		prev = ptr;
		ptr = ptr->left;
		while(ptr->right!=NULL){
			ptr = ptr->right;
		}
		e = ptr->data;			//reusing 'e'
		delete(ptr->data);
		prev->data = e;
	}else{
		if(dir==LEFT)		prev->left = NULL;
		else				prev->right = NULL;
	}
}

//	IN-ORDER-TARVERSEL OF A BST
void inOrderTraverse(struct node *ptr){
	if(ptr==NULL)	return;
	if((ptr->left)!=NULL)		inOrderTraverse(ptr->left);
	printf("%d ",ptr->data);
	if((ptr->right)!=NULL)		inOrderTraverse(ptr->right);
}

//	PRE-ORDER-TARVERSEL OF A BST
void preOrderTraverse(struct node *ptr){
	if(ptr==NULL)	return;
	printf("%d ",ptr->data);
	if((ptr->left)!=NULL)		inOrderTraverse(ptr->left);
	if((ptr->right)!=NULL)		inOrderTraverse(ptr->right);
}

//	POST-ORDER-TARVERSEL OF A BST
void postOrderTraverse(struct node *ptr){
	if(ptr==NULL)	return;
	if((ptr->left)!=NULL)		inOrderTraverse(ptr->left);
	if((ptr->right)!=NULL)		inOrderTraverse(ptr->right);
	printf("%d ",ptr->data);
}

//	METHOD TO FIND DEPTH OF BST
int depth(struct node *ptr){
	if(ptr==NULL)	return 0;
	return max(depth(ptr->left),depth(ptr->right)) + 1;
}

//	METHOD TO FIND SUM OF ALL ELEMENTS OF A BST
int add(struct node *ptr){
	int sum = 0;
	if(ptr==NULL)	return 0;
	if((ptr->left)!=NULL)		sum += add(ptr->left);
	if((ptr->right)!=NULL)		sum += add(ptr->right);
	return sum+ ptr->data;
}

//	METHOS TO COUNT NO OF ELEMENTS IN A BST
int noOfElem(struct node *ptr){
	int count = 0;
	if(ptr==NULL)			return 0;
	if(ptr->left!=NULL)		count += noOfElem(ptr->left);
	if(ptr->right!=NULL)	count += noOfElem(ptr->right);
	return 					count + 1;
}

//	METHOD TO CHECK STRICKNESS OF A BST
int isStrict(struct node *ptr){
	if(ptr->left==NULL && ptr->right==NULL)		return TRUE;
	if( (ptr->left!=NULL && ptr->right==NULL) || (ptr->left==NULL && ptr->right!=NULL) ){
		return FALSE;
	}else{
		return (isStrict(ptr->left) && isStrict(ptr->right));
	}
}

//	METHOD TO CHECK COMPLETENESS OF A BST
int isComplete(struct node *ptr, int d){
	if(d==1)			return TRUE;
	if(ptr==NULL)		return FALSE;
	return 				isComplete(ptr->left,d-1) && isComplete(ptr->right,d-1);
}

//METHOD TO CHECK IF THERE IS A ROOT TO LEAF PATH WITH GIVEN SUM
int isPathWithSum(struct node *ptr, int currSum, int reqSum){
	if(ptr==NULL && currSum!=reqSum) 									return FALSE;
//	printf("\nChecking for %d",ptr->data);
	currSum += ptr->data;
	if(currSum > reqSum)												return FALSE;
	if(currSum==reqSum && (ptr->left==NULL) && (ptr->right==NULL) )		return TRUE;
	if(currSum==reqSum && ((ptr->left!=NULL) || (ptr->right!=NULL)) )		return FALSE;
	return(isPathWithSum(ptr->left,currSum,reqSum) || isPathWithSum(ptr->right,currSum,reqSum) );
}

//METHOD TO FIND LOWEST COMMON ANCESTOR
int LCA(struct node *root, int a, int b){
	int dist = 0;
	if(root==NULL)		return FALSE;
	struct node *ptr = root;
	int flag = TRUE;
	while(flag){
		if( a < ptr->data && b < ptr->data){
			ptr = ptr->left;
		}
		else if(a>= ptr->data && b>= ptr->data){
			ptr = ptr->right;
		}
		else{
			flag = FALSE;
		}
	}
//	printf("\nCommon Ancestor : %d",ptr->data);
	struct node *temp ;
	temp = ptr;
	while(temp!=NULL && temp->data!=a){
		if(a < temp->data)		temp = temp->left;
		else					temp = temp->right;
		dist++;
	}
	if(temp==NULL){
		printf("Element %d not found",a);	
		return FALSE;
	}
	temp = ptr;
	while(temp!=NULL && temp->data!=b){
		if(b < temp->data)		temp = temp->left;
		else					temp = temp->right;
		dist++;
	}
	if(temp==NULL){
		printf("Element %d not found",b);	
		return FALSE;
	}
	return dist;
}

//	MAIN METHOD, EXECUTION STARTS HERE
int main(){
	int e,i,n=10; char ch='1';
	root = NULL;
// sample inputs
	int e1[10] = {8,5,6,7,3,0,9,1,2,4};
	int e2[10] = {10,5,15,4,6,12,17,1,7,20};
	printf("enter no of elements of tree : ");
//	scanf("%d",&n);
	printf("%d",n);
	for(i=0; i<n; i++){
//		scanf("%d",&e);
//		insert(e);
		insert(e1[i]);
	}
	printf("\nPre Order traversel : ");
	preOrderTraverse(root);
	printf("\nIn Order traversel : ");
	inOrderTraverse(root);
	printf("\nPost Order traversel : ");
	postOrderTraverse(root);
	printf("\ndepth of BST : %d\n",depth(root));
	printf("Sum = %d\n",add(root));
	printf("Is Strcit : %d\n",isStrict(root));
	printf("No of Elements : %d\n",noOfElem(root));
	printf("Is Complete : %d\n",isComplete(root,depth(root)));
//	printf("\nElement to be find : ");
//	scanf("%d",&e);
//	find(e);
//	printf("\nEnter element to delete : ");
//	scanf("%d",&e);
//	delete(e);
//	inOrderTraverse(root);
	printf("\nEnter Sum of path : ");
	scanf("%d",&n);
	printf("\nExists : %d",isPathWithSum(root,0,n));
	printf("\nEnter two elements for shortest Dist btw 2 nodes : ");
	scanf("%d %d",&e,&i);
	printf("\nDist : %d",LCA(root,e,i));
	return 0;
}