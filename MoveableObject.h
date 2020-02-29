#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_
#include"GameObject.h"
class MoveableObject:public GameObject
{
	public:
	MoveableObject():GameObject(){};
	virtual void move()=0;
	void draw(){};
	virtual ~MoveableObject(){};
};
#endif
