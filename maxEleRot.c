#include<stdio.h>

int findMaximum(int arr[], int N){
	int l=0,r=N-1, mid;
	while(l<r){
		mid = (l+r)/2;
		if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
			return arr[mid];
		else if(arr[mid]>=arr[mid-1] && arr[mid]<=arr[mid+1])
			l = mid+1;
		else if(arr[mid]<=arr[mid-1] && arr[mid]>=arr[mid+1])
			r = mid-1;
	}
	return arr[l];
}

int main() {
   int arr[] = {120, 100, 80, 20, 0};
   int n = sizeof(arr)/sizeof(arr[0]);
   printf("The maximum element is %d", findMaximum(arr, n));
   return 0;
}