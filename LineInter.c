#include<stdio.h>
#define min(a,b) ((a<b) ? a : b)
#define max(a,b) ((a>b) ? a : b)
#define true 1
#define false 0

struct point{
	int x;
	int y;
};

typedef struct point Point;

//method to check if Point r lies on line pq for colinear points p,q,r
int onSegment(Point p, Point q, Point r){
	if(	r.x >= min(p.x,q.x) && r.x <= max(p.x,q.x)
	&&	r.y >= min(p.y,q.y) && r.y <= max(p.y,q.y) )
		return true;
	return false;
}

int orientation(Point p, Point q, Point r){
	int val = (q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);
	if(!val)
		val = (val>0 ? 1 : 2);
	return val;
}

int doIntersect(Point p1, Point q1, Point p2, Point q2){
	int o1 = orientation(p1,q1,p2);
	int o2 = orientation(p1,q1,q2);
	int o3 = orientation(p2,q2,p1);
	int o4 = orientation(p2,q2,q1);

	//General Case
	if(o1!=o2 && o3!=o4)		return true;
	
	//Special cases
	
	//p2 lies on p1q1
	if(o1==0 && onSegment(p1,q1,p2))	return true;	
	//q2 lies on p1q1
	if(o2==0 && onSegment(p1,q1,q2))	return true;
	//p1 lies on p2q2
	if(o3==0 && onSegment(p2,q2,p1))	return true;
	//q1 lies on p2q2
	if(o4==0 && onSegment(p2,q2,q1))	return true;
	
	return false;
}
