#include<stdio.h>

char* stringConcat(char first[], char middle[], char last[]){
	char name[sizeof(first)+sizeof(middle)+sizeof(last)];
	int i = 0,k=0;
	printf("%d %d %d\n",sizeof(first),sizeof(middle),sizeof(last));
	for(i=0; i<sizeof(first); i++)
		name[k++] = first[i];
	name[k++] = ' '; 
	for(i=0; i<sizeof(middle); i++)
		name[k++] = middle[i];
	name[k++] = ' ';
	for(i=0; i<sizeof(last); i++)
		name[k++] = last[i];
	name[k] = '\0';
	printf("name: -%s-",name);
	return &(name[0]);
}

int main(){
	char first[] = "Rajat";
	char middle[] = "Singh";
	char last[] = "Bhal";
	printf("%s",stringConcat(first,middle,last));
}