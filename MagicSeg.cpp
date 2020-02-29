#include"MagicSeg.h"
MagicSeg::MagicSeg()
{
	x=0,y=0;
}
MagicSeg::MagicSeg(int X,int Y)
{
	x=X,y=Y;
}
void MagicSeg::draw()
{
	DrawCircle(x, y, 5, colors[AQUA]);
}
