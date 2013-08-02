//N-Queens problem
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

void printSol(int *x,int n){
	static int count =0;
	int i=1,j=1;
	printf("\n\nSol no - %d\n",++count);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)	
			printf("----");
		printf("\n|");
		for(j=1; j<=n; j++){
			if(x[i]==j)		printf(" Q |");
			else			printf("   |");
		}
		printf("\n");
	}
	for(i=1; i<=n; i++)
		printf("----");
}

int place(int k,int j, int *x){
	int i=0;
	for(i=1; i<k; i++){
		if((x[i]==j) || (abs(k-i)==abs(j-x[i])) )
			return false;
	}
	return true;
}

void nQueens(int i, int n, int *x){
	int j;
	if(i>n){
		printSol(x,n);
//		exit(0);
	}
	for(j=1; j<=n; j++){
		if(place(i,j,x)){
			x[i] = j;
			nQueens(i+1,n,x);
		}
	}
}


void main(){
	int n,i,j,k;
	printf("\nNo of Queens : ");
	scanf("%d",&n);
	int x[n+1];
	memset(x,0,sizeof(x));
/*	x[1] = 1;
	i=1,j=2,k=2;
	printf("\n%d %d",place(2,1,x),place(2,2,x));
*/	nQueens(1,n,x);
}
