#ifndef BUTTON_H
#define BUTTON_H
#include <deque>

struct Button
{
    float x;
    float y;

    float r;
    float g;
    float b;

    float w;
    float h;

    bool selected;

    Button();

    Button(float x, float y, float w, float h);

    Button(float x, float y, float w, float h, float r, float g, float b);

    void draw();

    // deque<Button *> buttons;

    bool colorSelect(float x, float y);
    bool erase(float x, float y);
    bool paint(float x, float y);

    void select();
    void deselect();
};

#endif
