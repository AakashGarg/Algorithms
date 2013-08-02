//seggregiate even and odd nos
#include<stdio.h>
#include<stdlib.h>

void segNos(int a[], int N){
	int i=0, ptr=0,t;
	for(i=0; i<N; i++){
		if(a[i]%2){
			t = a[i];
			a[i] = a[ptr];
			a[ptr] = t;
			ptr++;
		}
	}
}

int main(){
	int n, i;
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	segNos(a,n);
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	return 0;
}