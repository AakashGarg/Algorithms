//product Array puzzle
#include<stdio.h>
#include<stdlib.h>

void productArray(long *a, int n){
	long prod = 1,i, no,zeros=0, ind;
	for(i=0; i<n; i++){
		if(a[i]==0){
			zeros++;
			ind=i;
		}
	}
		
	if(zeros>1){
		for(i=0;i<n;i++)
			a[i]=0;
	}else if(zeros==1){
		prod = 1;
		for(i=0; i<n; i++){
			if(i!=ind){	
				prod *= a[i];
				a[i] = 0;
			}
		}
		a[ind] = prod;
	}else{
		for(i=0; i<n; i++)
			prod = a[i] *= prod;
		prod = 1;
		for(i=n-1; i>0; i--){
			no = a[i]/a[i-1];
			a[i] = a[i]/no*prod;
			prod *= no;
		}
		a[0] = prod;
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
	long a[n];
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	productArray(a,n);
	for(i=0; i<n; i++)
		printf("\n%ld",a[i]);
	return 0;
}