#ifndef MAGICSEG_H_
#define MAGICSEG_H_
#include"Position.h"
#include"util.h"
class MagicSeg:public Position
{
	protected:
	public:
	MagicSeg();
	MagicSeg(int,int);
	void draw();
	void move(){};
};
#endif
