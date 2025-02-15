#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
#include "headerFiles/isInsideTriangle.h"
#include "headerFiles/possibleTriangles.h"
#include "headerFiles/structures.h"
#include "headerFiles/minMax.h"
#include "headerFiles/getTriangleArea.h"

using namespace std;

void print(const vector<Point> &polygon)
{
    for (const Point &point : polygon)
    {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;
}

// O(n)
void partition(const vector<Point> &points, int &minIdx, int &maxIdx)
{
    vector<int> x;
    for (const Point &p : points)
    {
        x.push_back(p.x);
    }
    minMax(x, minIdx, maxIdx);
}

// O(n)
void divideRegions(const vector<Point> &points, Point min, Point max, vector<Point> &regionX, vector<Point> &regionY)
{
    Line line(min, max);
    for (const Point &p : points)
    {
        if (orientation(line, p) > 0)
        {
            regionX.push_back(p);
        }
        else if (orientation(line, p) < 0)
        {
            regionY.push_back(p);
        }
    }
}

// O(n)
void eliminateInteriorPoints(vector<Point> &region, Point &p1, Point &p2, Point &p3)
{
    vector<Point> newRegion;
    Triangle triangle(p1, p2, p3);
    for (const Point &p : region)
    {
        if (!isInside(triangle, p)) // O(1)
        {
            newRegion.push_back(p);
        }
    }
    region = newRegion;
}

// O(n)
Point getMaxAreaPoint(const vector<Point> &region, const Point &p1, const Point &p2)
{
    Point maxAreaPoint;
    int maxArea = INT_MIN;
    for (const Point &p : region)
    {
        int area = getArea(p1, p2, p); // O(1)
        if (area > maxArea)
        {
            maxArea = area;
            maxAreaPoint = p;
        }
    }
    return maxAreaPoint;
}

// O()
void solve(vector<Point> &region, Point &min, Point &max, vector<Point> &polygon)
{
    if (!region.empty())
    {
        Point maxAreaPoint = getMaxAreaPoint(region, min, max); // O(n)
        polygon.push_back(maxAreaPoint);

        cout << "max area point with partition (" << min.x << ", " << min.y << ") & (" << max.x << ", " << max.y << ") is: (" << maxAreaPoint.x << ", " << maxAreaPoint.y << ")" << endl;

        eliminateInteriorPoints(region, min, max, maxAreaPoint); // O(n)

        vector<Point> leftRegion, rightRegion;

        for (const Point &p : region) // O(n)
        {
            Line line1(min, maxAreaPoint), line2(max, maxAreaPoint);
            if (orientation(line1, p) > 0)
            {
                leftRegion.push_back(p);
            }
            else if (orientation(line2, p) < 0)
            {
                rightRegion.push_back(p);
            }
        }

        cout << "left Region: ";
        print(leftRegion);
        cout << "right Region: ";
        print(rightRegion);

        solve(leftRegion, min, maxAreaPoint, polygon);
        solve(rightRegion, maxAreaPoint, max, polygon);
    }
}

vector<Point> convexPolygon(const vector<Point> &points)
{
    if (points.size() <= 3)
    {
        return points;
    }
    else
    {
        vector<Point> polygon;

        // partition
        int maxIdx, minIdx;
        partition(points, minIdx, maxIdx);

        Point left = points[minIdx], right = points[maxIdx];
        polygon.push_back(left);
        polygon.push_back(right);

        // divide regions
        vector<Point> regionX, regionY;
        divideRegions(points, left, right, regionX, regionY);

        cout << "region X: ";
        print(regionX);
        cout << "region Y: ";
        print(regionY);

        // eliminate interior points
        solve(regionX, left, right, polygon);
        solve(regionY, left, right, polygon);

        return polygon;
    }
}

int main()
{
    vector<Point> points = {{3, 8}, {4, 10}, {7, 10}, {8, 6}, {1, 2}, {3, 5}, {1, 3}, {4, 6}, {3, 2}, {8, 4}};
    vector<Point> polygon = convexPolygon(points);
    cout << "convex polygon: ";
    print(polygon);
    return 0;
}