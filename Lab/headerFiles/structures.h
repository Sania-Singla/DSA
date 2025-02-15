#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <vector>
using namespace std;

class Point
{
public:
    int x, y;

    // Point(int x = 0, int y = 0) // will also work as a default constructor
    // {
    //     this->x = x;
    //     this->y = y;
    // }

    // or (efficient version because it directly intializes the values before entering the constr. body)
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Triangle
{
public:
    Point p1, p2, p3;
    Triangle(Point p1 = {0, 0}, Point p2 = {0, 0}, Point p3 = {0, 0}) : p1(p1), p2(p2), p3(p3) {}

    vector<Point> getPoints() const // so that it cannot modify any members of the class because where we are using it (triangle.getPoints()) that triangle object is const (we have declared it like that)
    {
        return {p1, p2, p3};
    }
};

class Line
{
public:
    Point p1, p2;
    Line(Point p1 = {0, 0}, Point p2 = {0, 0}) : p1(p1), p2(p2) {}

    vector<Point> getPoints() const
    {
        return {p1, p2};
    }
};

#endif