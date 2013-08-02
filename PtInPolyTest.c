//Point In Polygon test
#include "PtInPoly.c";

int main()
{
    Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    Point p = {20, 20};
    printf("%s\n",(pointInPolygon(polygon1, n, p)?"Yes": "No"));
 
    p.x=5, p.y=5;
    printf("%s\n",(pointInPolygon(polygon1, n, p)?"Yes": "No"));
	
    Point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
    p.x=3, p.y=3;
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    printf("%s\n",(pointInPolygon(polygon2, n, p)?"Yes": "No"));
	
    p.x=5, p.y=1;
    printf("%s\n",(pointInPolygon(polygon2, n, p)?"Yes": "No"));
	
	p.x=8, p.y=1;
    printf("%s\n",(pointInPolygon(polygon2, n, p)?"Yes": "No"));
	
    return 0;
}