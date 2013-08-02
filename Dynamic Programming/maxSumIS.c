#include<stdio.h>
#include<string.h>
#define max(a,b)	((a>b) ? a : b)

int maxSumIncrSubSeq(int arr[], int N){
	int dp[N],i,j;
	memset(dp,0,sizeof(dp));
	dp[N-1] = arr[N-1];
	for(i=N-2; i>=0; i--){
		for(j=i+1; j<N; j++){
			if(arr[j]>= arr[i])
				dp[i] = max(dp[i],dp[j]);
		}
		dp[i] += arr[i];
	}
	return dp[0];
}

int main() {
  int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Sum of maximum sum increasing subsequence is : %d\n",maxSumIncrSubSeq( arr, n ) );
  return 0;
}