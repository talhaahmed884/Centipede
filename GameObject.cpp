#include"GameObject.h"
GameObject::GameObject()
{
	position.setX(0),position.setY(0);
}
Position GameObject::getPosition()
{
	return position;
}
GameObject::~GameObject()
{
	position.setX(0),position.setY(0);
}
