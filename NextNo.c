#include<stdio.h>
#include<stdlib.h>
#define min(a,b)	((a<b) ? a : b)

int nextNo(int no){
	if(no/10==0)	return -1;
	int n, i, pivot=-1, minVal, reqI = n-1;
	for(n=0,i=no;i; i /=10,n++);
	char a[n+1];
	itoa(no,a,10);
	for(i=n-2; i>=0 && a[i]>=a[i+1]; i--);
	if((pivot = i)==-1)
		return -1;
	for(i=pivot+2, minVal=a[pivot+1],reqI=pivot+1; i<n; i++){
		if(a[i]<minVal && a[i]>a[pivot]){
			minVal = a[i];
			reqI = i;
		}
	}
	char t = a[pivot];
	a[pivot] = a[reqI];
	a[reqI] = t;
	return atoi(a);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("\nNext no : %d",nextNo(n));
	return 0;
}