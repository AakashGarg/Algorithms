#include<stdio.h>

int myStrcmp(char *dest, char *src){
	while(*dest && *src && (*dest == *src)){
		dest++; src++;
	}
	return (*dest-*src);
}

int main(int argc, char *argv[]){
	if(argc<3)	return 1;
	printf("\nDiff : %d",myStrcmp(*++argv,*++argv));
}