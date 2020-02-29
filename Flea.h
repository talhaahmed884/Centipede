#ifndef FLEA_H_
#define FLEA_H_
#include <GL/glut.h>
#include"MoveableObject.h"
#include"util.h"
class Flea:public MoveableObject
{
	protected:
	string check;
	int count;
	public:
	Flea();
	Flea(int,int);
	void draw();
	void move();
};
#endif
