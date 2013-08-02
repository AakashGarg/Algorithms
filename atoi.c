#include<stdio.h>

int atoi(char* s){
	int i=0;
	while(*s)
		i = 10*i + ((*s++)-'0');
	return i;
}

int main(int n, char *argv[]){
	int i=1;
	while(i++ < n)
		printf("\nInteger eqv. : %d",atoi(*++argv));
}