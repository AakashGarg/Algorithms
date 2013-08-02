#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b ? a : b)

int coinChange(int arr[], int M, int N){
	int dp[N+1],i,j;
	memset(dp,0,sizeof(dp));
	dp[0] = 1;

	for(i=0; i<M; i++)
        for(j=arr[i]; j<=N; j++)
            dp[j] += dp[j-arr[i]];
	return dp[N];
}

int main() {
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf("%d", coinChange(arr, m, n));
    return 0;
}