#include<stdio.h>

void f(int *a){
	(*a)++;
}

int main(){
	int i = 1, x = 1;
	while(x<=1000){
		x = 2*x;
		i++;
	}
	printf("%d,i);
	return 0;
}