#include "Point.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

Point::Point()
{
    x = 0;
    y = 0;

    r = 1;
    g = 0;
    b = 0;
}

Point::Point(float x, float y, float r, float g, float b)
{
    this->x = x;
    this->y = y;

    this->r = r;
    this->g = g;
    this->b = b;
}

// float Point::addPoint(float x, float y, float r, float g, float b)
// {
//     points.push_back(new Point(x, y, r, g, b));
// }

void Point::draw()
{
    glColor3f(r, g, b);
    glPointSize(10);

    glBegin(GL_POINTS);

    glVertex2f(x, y);

    glEnd();
}