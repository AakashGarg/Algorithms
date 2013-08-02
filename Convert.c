#include<stdio.h>
#include<string.h>

void swap(int arr[], int L1, int R1, int L2, int R2){
	if(L1>R1 || L2>R2)	return;
	int i=L1;
	for(L1; L1<R1 && L2<R2; L1++,L2++){
		int t = arr[L1];
		arr[L1] = arr[L2];
		arr[L2] = t;
	}
}

void convert(int arr[], int L, int R){
	int N = R-L;
	if(N==3)	return;
	swap(arr, L+N/6,L+N/3, L+N/3,L+N/2);
	swap(arr, L+N/2,L+2*N/3, L+2*N/3,L+5*N/6);
	swap(arr, L+N/3,L+N/2, L+N/2,L+2*N/3);
	
	convert(arr, L, L+N/2);
	convert(arr, L+N/2,R);
}

int main(){
	int n,i;
	printf("\nNo of elements : ");
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	convert(arr,0,n);
	printf("\nNew Sequence : ");
	for(i=0; i<n; i++)
		printf("%d ",arr[i]); 
}