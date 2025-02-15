#ifndef TRIANGLE_AREA_H
#define TRIANGLE_AREA_H

#include <iostream>
#include <vector>
#include "structures.h"
#include "determinant.h"
using namespace std;

int getArea(const Point &p1, const Point &p2, const Point &p3)
{
    vector<vector<int>> det = {
        {p1.x, p1.y, 1},
        {p2.x, p2.y, 1},
        {p3.x, p3.y, 1},
    };

    return abs(determinant(det) / 2);
}

// int main()
// {
//     Point p1 = {1, 1}, p2 = {3, 4}, p3 = {5, 2};
//     cout << "area is: " << getArea(p1, p2, p3) << endl;
//     return 0;
// }

#endif