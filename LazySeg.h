#ifndef LAZYSEG_H_
#define LAZYSEG_H_
#include"Position.h"
#include"util.h"
class LazySeg:public Position
{
	protected:
	public:
	LazySeg();
	LazySeg(int,int);
	void draw();
	void move(){};
};
#endif
