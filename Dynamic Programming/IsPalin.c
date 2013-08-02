#include<stdio.h>

int isPalin(int no){
	int t=no,rev=0;
	while(t){
		rev = rev*10+t%10;
		t /= 10;
	}
	while(rev && no){
		if(rev%10 != no%10)
			return 0;
		rev /= 10;
		no /= 10;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("\npalindrome : %d",isPalin(n));
	return 0;
}