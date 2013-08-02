#include<stdio.h>

int main(){
	char ch, string[100];
	int i = 0;
	while( i<sizeof(string)-1 && (ch=getchar())!='\n'){
		string[i++] = ch;
	}
	string[i] = '\0';
	printf("-%s-",string);
	return 0;
}