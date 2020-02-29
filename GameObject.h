#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include"Position.h"
class GameObject
{
	protected:
	Position position;
	public:
	GameObject();
	Position getPosition();
	virtual void draw()=0;
	virtual ~GameObject();
};
#endif
