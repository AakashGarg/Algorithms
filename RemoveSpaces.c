#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* removeUselessSpaces(char *ch, int n){
	int flag = 0;
	char *dest = ch, *temp = ch;
	for(; *ch; ch++){
		if(flag && (*ch) == ' ')		continue;
		if((*ch) ==' ' && !flag)		flag = 1;
		else 							flag = 0;
		*dest++ = *ch;
	}
	*dest = '\0';
	return temp;
}

int main(){
	char s[100];
	printf("\n Enter a string : ");
	gets(s);
	printf("Cleaned String : %s",removeUselessSpaces(s,strlen(s)));
	return 0;
}