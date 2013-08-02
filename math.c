#include<math.h>
#include<stdio.h>

#define PI 3.1416
#define MAX 180

int main(){
	int x = 0;
	float y;
	while(x<=MAX){
		y = (PI/MAX)*x;
		//printf("\ncos(%+4d) = %+1.25f",x,cos(y));
		printf("\ntan(%+4d) = %+35.25f",x,tan(y));
		x += 10;
	}
	return 0;
}