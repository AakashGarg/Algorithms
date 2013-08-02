#include<stdio.h>

int main()
{
int a=10,b=20,diff;
diff=&a-&b;
printf("Difference=%d",diff);
float a1=10.0,b1=20.0;
diff=&a1-&b1;
printf("\nDifference=%d",diff);
char a2='a',b2='z';
diff=&a2-&b2;
printf("\nDifference=%d",diff);
double a3=10.0,b3=20.0;
diff=&a3-&b3;
printf("\nDifference=%d",diff);
return 0;
}