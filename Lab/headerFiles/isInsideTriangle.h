#ifndef INSIDE_TRIANGLE_H
#define INSIDE_TRIANGLE_H

#include <iostream>
#include <vector>
#include "determinant.h"
#include "structures.h"

using namespace std;

int orientation(const Line &line, const Point p)
{
    Point p1 = line.p1, p2 = line.p2;
    vector<vector<int>> mat = {
        {p1.x, p1.y, 1},
        {p2.x, p2.y, 1},
        {p.x, p.y, 1},
    };
    return determinant(mat); // O(1) because always called with 3*3 matrix hence O(n!) => O(6)
}

// O(1)
// but if 'n' sided polygon then O(n*3!) => O(n*6) => O(n)
bool isInside(const Triangle &triangle, const Point &p)
{
    Point p1 = triangle.p1, p2 = triangle.p2, p3 = triangle.p3;
    Line line1 = {p1, p2}, line2 = {p2, p3}, line3 = {p3, p1};

    int d1 = orientation(line1, p); // O(n!) => O(3!) => O(6)
    int d2 = orientation(line2, p); // O(n!) => O(3!) => O(6)
    int d3 = orientation(line3, p); // O(n!) => O(3!) => O(6)

    // If all orientations are negative or all are positive, the point is inside
    return (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
}

// int main()
// {
//     Triangle triangle = {{3, 4}, {5, 2}, {1, 1}};
//     Point point = {2, 2};

//     if (isInside(triangle, point))
//     {
//         cout << "point is inside the given triangle." << endl;
//     }
//     else
//     {
//         cout << "point is outside or on the edge of given triangle." << endl;
//     }
// }

#endif