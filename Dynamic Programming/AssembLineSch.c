//Assembly Line Scheduling
#include<stdio.h>
#define NUM_STATION 4
#define min(a,b) ((a<b)?a:b)

int carAssembly(int S[2][NUM_STATION], int t[2][NUM_STATION], int e[], int x[]){
	int j, C0[NUM_STATION], C1[NUM_STATION];
	C0[NUM_STATION-1] = x[0]+S[0][NUM_STATION-1];
	C1[NUM_STATION-1] = x[1]+S[1][NUM_STATION-1];
	for(j=NUM_STATION-2; j>=0; j--){
		C0[j] = S[0][j] + min(C0[j+1],C1[j+1]+t[0][j+1]);
		C1[j] = S[1][j] + min(C1[j+1],C0[j+1]+t[1][j+1]);
	}
	return min(C0[0]+e[0], C1[0]+e[1]);
}

int main()
{
    int a[][NUM_STATION] = {{4, 5, 3, 2},
							{2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5},
							{0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};
 
    printf("%d", carAssembly(a, t, e, x));
    return 0;
}