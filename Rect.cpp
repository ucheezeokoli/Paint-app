#include "Rect.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Rect::Rect(){
	x = 0;
	y = 0;
	red = 1;
	green = 0;
	blue = 0;

	w = 0.2;
	h = 0.2;

	selected = false;
}

Rect::Rect(float x, float y, float w, float h){
	this->x = x;
	this->y = y;

	red = 1;
	green = 0;
	blue = 0;

	this->w = w;
	this->h = h;

	selected = false;
}

Rect::Rect(float x, float y, float w, float h, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;

	selected = false;
}

bool Rect::contains(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}


void Rect::moveUp(){
	y += 0.05;
}

void Rect::moveDown(){
	y -= 0.05;
}

void Rect::moveLeft(){
	x -= 0.05;
}

void Rect::moveRight(){
	x += 0.05;
}

void Rect::select(){
	selected = true;
}

void Rect::deselect(){
	selected = false;
}



void Rect::draw(){

	if (selected){

		glColor3f(1,1,1);
		glBegin(GL_LINES);

		glVertex2f(x, y);
		glVertex2f(x+w, y);

		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);
		
		glVertex2f(x, y-h);
		glVertex2f(x, y);

		glEnd();
		
		glColor3f(red, green, blue);

		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();

		
	}
	else{
		glColor3f(red, green, blue);

		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();
	}
}
