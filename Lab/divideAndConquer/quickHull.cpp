#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "../headerFiles/isInsideTriangle.h"
#include "../headerFiles/possibleTriangles.h"
#include "../headerFiles/structures.h"
#include "../headerFiles/minMax.h"
#include "../headerFiles/getTriangleArea.h"

using namespace std;

void print(const vector<Point> &polygon)
{
    for (const Point &point : polygon)
    {
        cout << "(" << point.x << "," << point.y << ") ";
    }
    cout << endl;
}

// O(n)
void partition(const vector<Point> &points, Point &min, Point &max)
{
    vector<int> x;
    int minIdx, maxIdx;
    for (const Point &p : points)
    {
        x.push_back(p.x);
    }
    minMax(x, minIdx, maxIdx);
    min = points[minIdx];
    max = points[maxIdx];
}

// O(n)
void divideRegions(const vector<Point> &points, const Line &line, vector<Point> &regionX, vector<Point> &regionY)
{
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
vector<Point> eliminateInteriorPoints(const vector<Point> &region, const Triangle &triangle)
{
    vector<Point> newRegion;
    for (const Point &p : region)
    {
        if (!isInside(triangle, p)) // O(1)
        {
            newRegion.push_back(p);
        }
    }
    return newRegion;
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

// T(n) = 2T(n/2) + O(n)
void solve(vector<Point> &region, Point &min, Point &max, vector<Point> &polygon)
{
    if (!region.empty())
    {
        Point maxAreaPoint = getMaxAreaPoint(region, min, max); // O(n)
        polygon.push_back(maxAreaPoint);

        cout << "max area point with partition (" << min.x << "," << min.y << ") & (" << max.x << "," << max.y << ") is: (" << maxAreaPoint.x << "," << maxAreaPoint.y << ")" << endl;

        // eliminate interior points, although unnecessary bs region chota ho jayega for further processing
        Triangle triangle(min, max, maxAreaPoint);
        region = eliminateInteriorPoints(region, triangle); // O(n)

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

        solve(leftRegion, min, maxAreaPoint, polygon);  // T(n/2)
        solve(rightRegion, maxAreaPoint, max, polygon); // T(n/2)
    }
}

// O()
vector<Point> quickHull(const vector<Point> &points)
{
    if (points.size() <= 3)
    {
        return points;
    }
    else
    {
        vector<Point> polygon;

        // partition
        Point min, max;
        partition(points, min, max);               // O(n)
        polygon.insert(polygon.end(), {min, max}); // or .push_back() twice

        cout << "partition is: (" << min.x << "," << min.y << ") (" << max.x << "," << max.y << ")" << endl;

        // divide regions X & Y
        vector<Point> regionX, regionY;
        Line line(min, max);
        divideRegions(points, line, regionX, regionY); // O(n)

        cout << "region X: ";
        print(regionX);
        cout << "region Y: ";
        print(regionY);

        // proceed
        cout << "processing with region X:" << endl;
        solve(regionX, min, max, polygon); // T(n/2)
        cout << "processing with region Y:" << endl;
        solve(regionY, max, min, polygon); // because orientation got opposite so min & max orientation wise changed // T(n/2)

        return polygon;
    }
}

int main()
{
    vector<Point> points = {
        {1, 2},
        {1, 3},
        {3, 5},
        {3, 8},
        {4, 6},
        {4, 10},
        {7, 10},
        {3, 2},
        {8, 6},
        {8, 4},
    };
    vector<Point> polygon = quickHull(points); // O()
    cout << "convex polygon: ";
    print(polygon);
    return 0;
}