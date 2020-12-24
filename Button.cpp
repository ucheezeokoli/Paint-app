#include "Button.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Button::Button()
{
    x = 0;
    y = 0;

    r = 1;
    g = 0;
    b = 0;

    w = 0.2;
    h = 0.2;

    selected = false;
}

Button::Button(float x, float y, float w, float h)
{
    this->x = x;
    this->y = y;

    r = 1;
    g = 0;
    b = 0;

    this->w = w;
    this->h = h;

    selected = false;
}

Button::Button(float x, float y, float w, float h, float r, float g, float b)
{
    this->x = x;
    this->y = y;

    this->r = r;
    this->g = g;
    this->b = b;

    this->w = w;
    this->h = h;

    selected = false;
}

bool Button::colorSelect(float x, float y)
{
    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

bool Button::erase(float x, float y)
{
    return (x > -0.95 && x < -0.95 + 0.1 && y < -0.25 && y > -0.25 - 0.1);
}

bool Button::paint(float x, float y)
{
    return (x > -0.95 && x < -0.95 + 0.1 && y < 0 && y > -0.1);
}

void Button::select()
{
    selected = true;
}

void Button::deselect()
{
    selected = false;
}

void Button::draw()
{

    if (selected)
    {

        glColor3f(1, 1, 1);
        glBegin(GL_LINES);

        glVertex2f(x, y);
        glVertex2f(x + w, y);

        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);

        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);

        glVertex2f(x, y - h);
        glVertex2f(x, y);

        glEnd();

        glColor3f(r, g, b);

        glBegin(GL_POLYGON);

        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);

        glEnd();
    }
    else
    {
        glColor3f(r, g, b);

        glBegin(GL_POLYGON);

        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);

        glEnd();
    }
}
