//Point in Polygon
#include "LineInter.c";
#define INF 100000

int pointInPolygon(Point poly[], int n, Point p){
	int i=0, count=0;
	Point ext = {INF,p.y};
/*	for(i=1; i<n; i++)
		ext.x = max(poly[i].x,ext.x);
	ext.x += 10;
*/	for(i=1; i<=n; i++){
		if(doIntersect(poly[i-1],poly[i%n],p,ext)){
			if(orientation(poly[i-1],p,poly[i%n])==0)
				return true;
			count++;
		}
	}
	return count%2? true : false;
}