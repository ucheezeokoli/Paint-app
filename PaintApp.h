#ifndef PAINTAPP_H
#define PAINTAPP_H

struct PaintApp
{
    // float x;
    // float y;

    // float r;
    // float g;
    // float b;

    PaintApp(); //This is a default constructor

    PaintApp(float x, float y, float r, float g, float b);

    void NewPoint(float x, float y, float r, float g, float b);

    void draw();

    void colorSelect(float x, float y);

    void paint_or_erase(float x, float y);

    void erase(float x, float y);
    void colorButtons();
};

#endif