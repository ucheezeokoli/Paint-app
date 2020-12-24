#include <iostream>
#include <deque>

#include "PaintApp.h"
#include "Point.h"
#include "Button.h"

using namespace std;

deque<Point *> points;
deque<Button *> buttons;

Button eraseButton(-0.95, -0.25, 0.1, 0.1, 0, 0, 0);
Button paintButton(-0.95, 0, 0.1, 0.1, 0, 0, 0);

bool eraser = false;

float red;
float green;
float blue;

PaintApp::PaintApp()
{
}

void PaintApp::colorSelect(float x, float y)
{
    for (auto i = buttons.begin(); i != buttons.end(); i++)
    {
        if ((*i)->erase(x, y))
        {
            eraser = true;
        }
        else if ((*i)->paint(x, y))
        {
            eraser = false;
        }
    }

    if (!eraser)
    {
        for (auto i = buttons.begin(); i != buttons.end(); i++)
        {
            if ((*i)->colorSelect(x, y))
            {
                red = (*i)->r;
                green = (*i)->g;
                blue = (*i)->b;
                NewPoint(x, y, red, green, blue);
            }
        }
    }
}

void PaintApp::paint_or_erase(float x, float y)
{
    if (!(x > -1 && x < -0.55 && y > -0.4 && y < 0.45))
    {
        if (eraser)
        {
            NewPoint(x, y, 1, 1, 1);
        }
        else
        {
            NewPoint(x, y, red, green, blue);
        }
    }
}

void PaintApp::NewPoint(float x, float y, float r, float g, float b)
{
    points.push_front(new Point(x, y, r, g, b));
}

void PaintApp::draw()
{
    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i]->x << endl;
        points[i]->draw();
    }

    for (int j = 0; j < buttons.size(); j++)
    {
        buttons[j]->draw();
    }
    paintButton.draw();
    eraseButton.draw();
}

void PaintApp::colorButtons()
{
    buttons.push_back(new Button(-0.95, 0.3, 0.1, 0.1, 1, 0, 0)); //Red button
    buttons.push_back(new Button(-0.85, 0.3, 0.1, 0.1, 0, 1, 0)); //Green button
    buttons.push_back(new Button(-0.75, 0.3, 0.1, 0.1, 0, 0, 1)); //Blue button
}

void PaintApp::erase(float x, float y)
{
    for (int i = 0; i < points.size(); i++)
    {
        if (points[i]->x == x)
        {
            points.erase(points.begin() + i);
            // points.pop_front();
        }
    }
}