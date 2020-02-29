#ifndef SEGMENT_H_
#define SEGMENT_H_
#include"MoveableObject.h"
#include"LazySeg.h"
#include"MagicSeg.h"
#include"Mushroom.h"
#include"util.h"
class Segment:public MoveableObject
{
	protected:
	MagicSeg magicseg;
	LazySeg *lazyseg;
	int lazysegCount;
	string check;
	public:
	Segment();
	Segment(int,int,int);
	Segment(int,int);
	void draw();
	void move();
	void avoidMuhsrooms(Position *,int count);
};
#endif
