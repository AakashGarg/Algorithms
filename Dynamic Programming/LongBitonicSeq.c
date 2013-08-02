#include<stdio.h>
#include<string.h>
#define max(a,b)	(((a)>(b)) ? (a) : (b))

int longestBitonicSeq(int arr[], int N){
	int lis[N],lds[N],i,j;
	memset(lis,0,sizeof(lis));
	memset(lds,0,sizeof(lds));
	lis[0] = lds[N-1] = 1;
	
	for(i=1; i<N; i++){
		for(j=0; j<i; j++){
			if(arr[j]<=arr[i])
				lis[i] = max(lis[i],lis[j]);
		}
		lis[i]++;
	}
	
	for(i=N-2; i>=0; i--){
		for(j=i+1; j<N; j++){
			if(arr[i]>=arr[j])
				lds[i] = max(lds[i],lds[j]);
		}
		lds[i]++;
	}
	
	int ans = 0;
	for(i=0; i<N; i++)
		ans = max(ans,lis[i]+lds[i]-1);
	return ans;
}

int main() {
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of LBS is %d\n", longestBitonicSeq( arr, n ) ); 
	return 0;
}