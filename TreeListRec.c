//THE GREAK TREE LIST RECURSION PROBLEM
//Statement: to convert a binary tree to a Doubly Linked List

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node * newNode(int data){
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(struct node **root, int data){
	struct node *temp = *root;
	if(!temp)
		*root = newNode(data);
	if((*root)->data < data)
}

struct node * convert(struct node **root, struct node *prev, struct node *parent){
	if(!*root)		return NULL;
	if((*root)->right)
		convert( &((*root)->right), prev, *root);
	else{
		(*root)->right = prev;
		if(prev)	
			prev->left = *root;
	}
	
	if((*root)->left)
		return convert((*root)->left,*root,parent);
	else{
		(*root)->left = parent;
		if(parent)
			parent->right = *root;
		return *root;
	}
}

int main(){
	
}