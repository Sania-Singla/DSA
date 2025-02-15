#include <iostream>
#include <vector>
#include "headerFiles/isInsideTriangle.h"
#include "headerFiles/possibleTriangles.h"
#include "headerFiles/structures.h"

using namespace std;

void print(const vector<Point> &polygon)
{
    for (const Point &point : polygon)
    {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;
}

vector<Point> convexPolygon(const vector<Point> &points)
{
    vector<Point> polygon;
    vector<Triangle> triangles = possibleTriangles(points);
    for (const Point &point : points)
    {
        bool isInsideSomeTriangle = false;
        for (const Triangle &triangle : triangles)
        {
            if (isInside(triangle, point))
            {
                isInsideSomeTriangle = true;
                break;
            }
        }
        if (!isInsideSomeTriangle)
        {
            polygon.push_back(point);
        }
    }
    return polygon;
}

int main()
{
    vector<Point> points = {{3, 8}, {4, 10}, {7, 10}, {8, 6}, {1, 2}, {3, 5}, {1, 3}, {4, 6}, {3, 2}, {8, 4}};
    vector<Point> polygon = convexPolygon(points);
    print(polygon);
    return 0;
}