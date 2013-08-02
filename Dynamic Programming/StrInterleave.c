#include<stdio.h>
#include<string.h>
#define true 1
#define false 0

int isInterleaved(char* A, char* B, char* C){
	int M = strlen(A);
	int N = strlen(B);
	int dp[M+1][N+1];
	if(strlen(C)!=(M+N))		return false;
	memset(dp,false,sizeof(dp));
	int i,j;
	for(i=0; i<=M; i++){
		for(j=0; j<=N; j++){
			if(i==0 && j==0)
				dp[i][j] = true;
			else if(i==0 && B[j-1]==C[j-1])
				dp[i][j] = dp[i][j-1];
			else if(j==0 && A[i-1]==C[i-1])
				dp[i][j] = dp[i-1][j];
			else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
				dp[i][j] = dp[i-1][j];
			else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
				dp[i][j] = dp[i][j-1];
			else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
		}
	}
	return dp[M][N];
}


void test(char *A, char *B, char *C) {
    if (isInterleaved(A, B, C))
        printf("\n%s is interleaved of %s and %s",C,A,B);
    else
        printf("\n%s is not interleaved of %s and %s",C,A,B);
}
 
// Driver program to test above functions
int main() {
    test("XXY", "XXZ", "XXZXXXY");
    test("XY" ,"WZ" ,"WZXY");
    test ("XY", "X", "XXY");
    test ("YX", "X", "XXY");
    test ("XXY", "XXZ", "XXXXZY");
    return 0;
}