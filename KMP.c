//KMP Algorithm
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CHARS 26

int** createFSM(char *pat){
	static int **fsm;
	int i,j,x=0,n=strlen(pat);
	fsm = (int **) malloc(sizeof(int *)*CHARS);
	for(i=0; i<CHARS; i++){
		fsm[i] = (int *)malloc(sizeof(int)*n);
		fsm[i][0] = 0;
	}
	fsm[(*pat)-'a'][0] = 1;
	for(j=1; j<n; j++){
		for(i=0; i<CHARS; i++)
			fsm[i][j] = fsm[i][x];
		fsm[*(pat+j)-'a'][j] = j+1;
		x = fsm[*(pat+j)-'a'][x];
	}
	return fsm;
}

int KMP(char *pat, char *txt){
	int state=0,i,n=strlen(pat),m=strlen(txt);
	int **fsm = createFSM(pat);
	for(i=0; i<m; i++){
		state = fsm[*(txt+i)-'a'][state];
		if(state==n)
			return i-state+1;
	}
	return -1;
}

int main(int argc, char *argv[]){
	int j=0;
	if(argc<3)
		return -1;
	char *pat = argv[1];
	char *txt = argv[2];
	int i = KMP(pat,txt);
	if(i==-1)
		printf("not found");
	else{
		printf("\n%s\n");
		for(j=0; j<strlen(txt) && j<i; j++)
			printf(" ");
		printf("^");
		printf("\nFound at index : %d",i);
	}
	return 0;
}