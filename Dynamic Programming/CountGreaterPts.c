#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	int y;
};

int compare(const void * p, const void * q){
	struct node *a = (struct node *) p;
	struct node *b = (struct node *) q;
	if(a->x < b->x)
		return -1;
	else if(a->x > b->x)
		return 1;
	else if(a->y < b->y)
		return -1;
	else if(a->y > b->y)
		return 1;
	else 
		return 0;
}

int * count(struct node a[], int n){
	int *dp = malloc(sizeof(int)*n), i;
	dp[n-1] = 0;
	qsort(a,n,sizeof(struct node),compare);
	for(i=n-2; i>=0; i--){
		if(a[i].x<a[i+1].x && a[i].y<a[i+1].y)
			dp[i] = dp[i+1] + 1;
		else
			dp[i] = dp[i+1];
	}
	return dp;
}

int main(){
	int n,i,x,y;
	scanf("%d",&n);
	struct node a[n];
	for(i=0; i<n; i++){
		scanf("%d %d",&x,&y);
		a[i].x = x;
		a[i].y = y;
	}
	int *c = count(a,n);
	for(i=0; i<n; i++)
		printf("%d ",c[i]);
	return 0;
}