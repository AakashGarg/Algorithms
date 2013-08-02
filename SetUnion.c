//union and intersection of 2 arrays
#include<stdio.h>
#include<stdlib.h>
#define min(a,b)	((a<b) ? a : b)

void set(int a[], int b[], int n1, int n2, int *l1, int *l2, int uni[], int inter[]){
	int i=0,j=0;
	*l1 = 0, *l2=0;
	while(i<n1 && j<n1){
		if(a[i]==b[j]){
			uni[(*l1)++] = a[i];
			inter[(*l2)++] = a[i++] = b[j++];
		}else if(a[i]<b[j])
			uni[(*l1)++] = a[i++];
		else
			inter[(*l2)++] = b[j++];
	}
}

int main(){
	int n1, n2, i;
	scanf("%d %d", &n1,&n2);
	int a[n1], b[n2];
	for(i=0; i<n1; i++)
		scanf("%d",&a[n1]);
	for(i=0; i<n2; i++)
		scanf("%d",&b[n2]);
	int l1,l2, *uni, *inter;
	uni = malloc(sizeof(int)*(n1+n2));
	inter = malloc(sizeof(int)*min(n1,n2)); 
	set(a,b,n1,n2,&l1,&l2,uni,inter);
	for(i=0; i<l1; i++)
		printf("%d ",uni[i]);
	printf("\n");
	for(i=0; i<l2; i++)
		printf("%d ",inter[i]);
	return 0;
}