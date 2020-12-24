#ifndef RECT_H
#define RECT_H


struct Rect {
	float x;
	float y;

	float red;
	float green; 
	float blue;

	float w;
	float h;

	bool selected;

	Rect(); // This is a default constructor (takes no parameters)

	Rect(float x, float y, float w, float h);

	Rect(float x, float y, float w, float h, float red, float green, float blue);

	void draw();

	bool contains(float x, float y);


	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void select();
	void deselect();


};




#endif
