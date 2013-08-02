#include<stdio.h>
#include<stdlib.h>
#define max(a,b)	( ((a)>(b)) ? (a) : (b) )

int longSinSeq(int arr[], int n){
	int i=0, incr, decr, a,b;
	incr = decr = 1;
	for(i=n-2; i>=0; i--,incr = a, decr = b){
		a = max( ((arr[i]-arr[i+1]>0) ? (1+decr) : incr), incr );
		b = max( ((arr[i]-arr[i+1]<0) ? (1+incr) : decr), decr );
	}
	return max(incr,decr);
}

int main(){
	int n, i;
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d, ",&a[i]);
	printf("sol : %d",longSinSeq(a,n));
	return 0;
}