#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define min(a,b) ((a<b)? a : b)
#define infinity INT_MAX

int minJumps(int* a, int n){
	int i,j,minVal,jumps[n];
	for(i=0; i<n-1; i++)
		jumps[i] = infinity;
	jumps[n-1] = 0;
	for(j=n-2; j>=0; j--){
		minVal = infinity;
		for(i=j+1; i<n && i<=j+a[j]; i++)
			minVal = min(jumps[i],minVal);
		if(minVal!=infinity)
			jumps[j] = minVal+1;
	}
	return jumps[0];
}

int main(){
	int n,i, *a;
	scanf("%d",&n);
	a = (int *) malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	printf("\n%d",minJumps(a,n));
}