#include<stdio.h>

#define max(a,b)	((a>b) ? a : b)
#define min(a,b)	((a<b) ? a : b)
#define true 1
#define false 0

int isConsec(int a[], int n){
	int i=1, sum = a[0], minVal = a[0], maxVal = a[0];
	for(i=1; i<n; i++){
		sum += a[i];
		minVal = min(minVal,a[i]);
		maxVal = max(maxVal,a[i]);
	}
	int prevSum = (minVal ? minVal*(minVal-1)/2 : 0);
//	return (((maxVal*(maxVal+1)/2) - prevSum)==sum) ? true : false; 
	return n*(2*minVal+n-1)==2*sum;
}

int main(){
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n ;i++)
		scanf("%d",&a[i]);
	printf("\n%d",isConsec(a,n));
	return 0;
}