#include<stdio.h>
#include<string.h>
#define max(a,b)	((a>b) ? a : b);

struct chainNode{
	int l;
	int r;
};
typedef struct chainNode* chain;

int compare(const void* a, const void* b){
	struct chainNode* a1 = (struct node *) a;
	struct chainNode* b1 = (struct node *) b;
	if(a1->l<b1->l)			return -1;
	else if(a1->l > b1->l)	return 1;
	else if(a1->r < b1->r)	return -1;
	else if(a1->r > b1->r)	return 1;
	else 					return 0;
}

int longestChain(struct chainNode arr[], int N){
	qsort(arr,N,sizeof(struct chainNode),compare);
	int dp[N],i,j;
	memset(dp,0,sizeof(dp));
	dp[N-1] = 1;
	for(i=N-2; i>=0; i--){
		for(j=i+1; j<N; j++){
			if(arr[i].r-arr[j].l <=0)
				dp[i] = max(dp[j],dp[i]);
		}
		dp[i]++;
	}
	return dp[0];
}

int main()
{
    struct chainNode arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60} };
    int N = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is : %d\n", longestChain( arr, N ));
    return 0;
}