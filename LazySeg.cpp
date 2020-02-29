#include"LazySeg.h"
LazySeg::LazySeg()
{
	x=0,y=0;
}
LazySeg::LazySeg(int X,int Y)
{
	x=X,y=Y;
}
void LazySeg::draw()
{
	DrawCircle(x, y, 5, colors[AQUA]);
}
