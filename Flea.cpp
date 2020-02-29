#include"Flea.h"
Flea::Flea()
{
	position.setX(0),position.setY(0);
	check="on";
	count=0;
}
Flea::Flea(int X,int Y)
{
	position.setX(X),position.setY(Y);
	check="on";
	count=0;
}
void Flea::draw()
{
	if(check=="off")
	{
		count++;
		if(count==100)
		{
			position.setX(GetRandInRange(5,995));
			position.setY(GetRandInRange(500,300));
			check="on";
			count=0;
		}
	}
	if(check=="on")
	{
		DrawCircle(position.getX(), position.getY(), 10, colors[AQUA]);
	}
}
void Flea::move()
{
	if(position.getY()>=0)
	{
		position.setY(position.getY()-10);
	}
	else
	{
		check="off";
	}
}
