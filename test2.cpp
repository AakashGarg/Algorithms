#include <iostream>
#include "LineInter.c"
using namespace std;
 
// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10000
 
// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point lies on the segment from polygon[i] to
            // polygon[(i+1)%n], then immediately return true
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return true;
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}
 
// Driver program to test above functions
int main()
{
    Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    Point p = {20, 20};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
 
    p.x=5, p.y=5;
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
 
    Point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
    p.x=3, p.y=3;
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    p.x=5, p.y=1;
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    p.x=8, p.y=1;
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";
 
    return 0;
}