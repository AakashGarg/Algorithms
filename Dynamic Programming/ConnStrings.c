#include<stdio.h>
#include<stdlib.h>

int connStrings(char *arr[], int n){
	int cnt[26],i=0, count=0;
	char *ch;
	for(i=0; i<26; i++)
		cnt[i] = 0;
	for(i=1; i<=n; i++){
		ch = *(arr+i);
		cnt[*ch - 'a']++;
		while(*ch != '\0') 		ch++;
		ch--;
		cnt[*ch -'a']--;
	}
	for(i=0; i<26; i++)
		if(cnt[i]%2)		
			count++;
	return ((count==2) ? 1 : 0);
}

int main(int argc, char *argv[]){
	printf("%s",(connStrings(argv,argc-1) ? "true" : "false"));
}