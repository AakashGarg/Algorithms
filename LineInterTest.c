//LineInterTest
#include "LineInter.c"

int main()
{
    Point p1 = {1, 1}, q1 = {10, 1};
    Point p2 = {1, 2}, q2 = {10, 2};
 
    printf("%s\n",(doIntersect(p1, q1, p2, q2)? "Yes":"No"));
 
    p1.x = 10,p1.y=0, q1.x = 0,q1.y=10;
    p2.x = 0,p2.y=0, q2.x = 10,q2.y=10;
    printf("%s\n",(doIntersect(p1, q1, p2, q2)? "Yes":"No"));
 
	p1.x = -5,p1.y=-5, q1.x = 0,q1.y=0;
    p1.x = 1,p1.y=1, q1.x = 10,q1.y=10;
    printf("%s\n",(doIntersect(p1, q1, p2, q2)? "Yes":"No"));
 
    return 0;
}