//Subset Sum Problem
#include<stdio.h>
#include<string.h>

#define true 1
#define false 0

int isSubsetSum(int set[], int n, int S){
	int dp[S+1][n+1], i, sum;
	memset(dp,0,sizeof(dp));
	for(i=0; i<=n; i++)
		dp[0][i] = true;
	for(sum = 1; sum<=S; sum++){
		for(i=1; i<=n; i++){
			dp[sum][i] = dp[sum][i-1];
			if(sum>=set[i-1]){
				dp[sum][i] = dp[sum][i] || dp[sum-set[i-1]][i-1];
			}
		}
	}
	return dp[S][n];
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}