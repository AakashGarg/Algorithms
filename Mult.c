#include<stdio.h>

long mult(int a, int b){
	if(a==1)	return b;
	if(b==1)	return a;
	if(a>b)		return a+mult(a,b-1);
	else		return b+mult(a-1,b);
}

int main(){
	int a, b;
	printf("Enter two nos : ");
	scanf("%d %d",&a,&b);
	printf("%d*%d = %ld",a,b,mult(a,b));
	return 0;
}