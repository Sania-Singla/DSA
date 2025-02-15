#ifndef POSSIBLE_TRIANGLES_H
#define POSSIBLE_TRIANGLES_H

#include <iostream>
#include <vector>
#include "determinant.h"
#include "structures.h"

using namespace std;

void print(const vector<Triangle> &triangles)
{
    for (const Triangle &triangle : triangles)
    {
        for (const Point &point : triangle.getPoints())
        {
            cout << "(" << point.x << ", " << point.y << ") ";
        }
        cout << endl;
    }
}

// O(1)
bool areCollinear(const Point &p1, const Point &p2, const Point &p3)
{
    vector<vector<int>> mat = {
        {p1.x, p1.y, 1},
        {p2.x, p2.y, 1},
        {p3.x, p3.y, 1},
    };
    int det = determinant(mat);
    return det == 0; // could be compiler issue if return in same line
}

// O(n^3)
vector<Triangle> possibleTriangles(const vector<Point> &points)
{
    vector<Triangle> triangles;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                Point p1 = points[i], p2 = points[j], p3 = points[k];
                if (!areCollinear(p1, p2, p3))
                {
                    Triangle triangle(p1, p2, p3);
                    triangles.push_back(triangle);
                }
            }
        }
    }
    return triangles;
}

// int main()
// {
//     vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 0}};
//     vector<Triangle> triangles = possibleTriangles(points);
//     print(triangles);
//     return 0;
// }

#endif