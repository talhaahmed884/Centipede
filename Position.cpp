#include"Position.h"
Position::Position()
{
	x=0,y=0;
}
Position::Position(int X,int Y)
{
	x=X,y=Y;
}
void Position::setX(int X)
{
	x=X;
}
void Position::setY(int Y)
{
	y=Y;
}
int Position::getX()
{
	return x;
}
int Position::getY()
{
	return y;
}
Position::~Position()
{
	x=0,y=0;
}
