#include<stdio.h>

long fact(int n){
	return (n==1 ? 1 : n*fact(n-1) );
}

int main(){
	int n;
	printf("Enter a no : ");
	scanf("%d",&n);
	printf("%ld",fact(n));
	return 0;
}