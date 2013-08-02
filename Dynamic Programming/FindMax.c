#include<stdio.h>
#include<stdlib.h>

int findMax(int **a, int m, int n){
	int i,row,ind;
	for(i=n, row=0, ind=0; i>0 && row<m; row++){
		while(i>0 && a[row][i-1]){
			i--; 
			ind = row;
		}
	}
	return ind;
}

int main(){
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	int **a = (int**)malloc(sizeof(int*)*m);
	for(i=0; i<m; i++)
		a[i] = (int*)malloc(sizeof(int)*n);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	}
	printf("\nSol : %d",findMax(a,m,n));
	return 0;
}