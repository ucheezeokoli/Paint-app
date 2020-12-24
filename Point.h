#ifndef POINT_H
#define POINT_H
#include <deque>

struct Point
{
    float x;
    float y;

    float r;
    float g;
    float b;

    Point(); // This is a default constructor

    Point(float x, float y, float r, float g, float b);

    float addPoint(float x, float y, float r, float g, float b);

    void draw();
};

#endif