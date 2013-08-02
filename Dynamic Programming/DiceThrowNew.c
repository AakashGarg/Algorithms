#include<stdio.h>
#include<string.h>
#define min(a,b) ((a<b)? (a) : (b))

void printData(int *x, int n){
	int i=0;
	printf("\n-- ");
	for(i=0; i<n; i++)
		printf("%d ",x[i]);
}

//O(n2)
int findWays(int m, int n, int X){
	if(X<n || X>n*m)		return 0;
	int dp[min(X-n+1,m)],i,j;
	int len = sizeof(dp)/sizeof(dp[0]);
	for(i=0; i<len; i++)
		dp[i] = 1;
	for(i=1; i<n; i++){
		for(j=1; j<len; j++)
			dp[j] += dp[j-1];
	}
	return dp[len-1];
}

//O(n) solution
int findWay(int m, int n, int X){
	if(X<n || X>n*m)		return 0;
	if(X==n || n==1)		return 1;
	int i = n, j = min(X-n+1,m);
	int sol = 1,k=0;
	for(i=0; i<=n-2; i++)
		sol *= j+i;
	for(i=2; i<n; i++)
		sol /= i;
	return sol;
}

int main(){
	int n,m,X;
	printf("Enter n,m,x : ");
	scanf("%d %d %d",&n,&m,&X);
    printf("\nfindWays(4, 2, 1) : %d",findWay(m,n,X));
	printf("\nfindWays(4, 2, 1) : %d",findWay(4, 2, 1));
	printf("\nfindWays(2, 2, 3) : %d",findWay(2, 2, 3));
    printf("\nfindWays(6, 3, 8) : %d",findWay(6, 3, 8));
    printf("\nfindWays(4, 2, 5) : %d",findWay(4, 2, 5));
	printf("\nfindWays(4, 3, 5) : %d",findWay(15, 5, 11));
}