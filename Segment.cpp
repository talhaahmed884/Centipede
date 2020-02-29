#include"Segment.h"
Segment::Segment()
{
	magicseg.setX(0),magicseg.setY(0);
	lazyseg=new LazySeg[5];
	for(int a=0;a<lazysegCount;a++)
	{
		lazyseg[a].setX(0);
		lazyseg[a].setY(0);
	}
	lazysegCount=10;
	check="\0";
}
Segment::Segment(int MGX,int MGY,int count)
{
	magicseg.setX(MGX),magicseg.setY(MGY);
	lazysegCount=count;
	lazyseg=new LazySeg[count];
	int temp=MGX;
	for(int a=0;a<count;a++)
	{
		temp-=10;
		lazyseg[a].setX(temp);
		lazyseg[a].setY(MGY);
	}
	check="\0";
}
Segment::Segment(int MGX,int MGY)
{
	magicseg.setX(MGX),magicseg.setY(MGY);
	lazysegCount=10;
	lazyseg=new LazySeg[lazysegCount];
	int temp=MGX;
	for(int a=0;a<lazysegCount;a++)
	{
		temp-=10;
		lazyseg[a].setX(temp);
		lazyseg[a].setY(MGY);
	}
	check="right";
}
void Segment::draw()
{
	DrawCircle(magicseg.getX(),magicseg.getY(), 5, colors[YELLOW]);
	for(int a=0;a<lazysegCount;a++)
	{
		DrawCircle(lazyseg[a].getX(), lazyseg[a].getY(), 5, colors[BROWN]);
	}
}
void Segment::move()
{
	if(magicseg.getX()>=995)
	{
		check="left turn";
	}
	if(magicseg.getX()<=5)
	{
		check="right turn";
	}
	if(check=="left turn")
	{
		magicseg.setY(magicseg.getY()-10);
		check="left";
	}
	if(check=="right turn")
	{
		magicseg.setY(magicseg.getY()-10);
		check="right";
	}
	if(check=="left")
	{
		magicseg.setX(magicseg.getX()-2);
	}
	if(check=="right")
	{
		magicseg.setX(magicseg.getX()+2);
	}
	for(int a=lazysegCount-1;a>=1;a--)
	{
		if(check=="right")
		{
			lazyseg[a].setX(lazyseg[a-1].getX()-6);
			lazyseg[a].setY(lazyseg[a-1].getY());
		}
		if(check=="left")
		{
			lazyseg[a].setX(lazyseg[a-1].getX()+6);
			lazyseg[a].setY(lazyseg[a-1].getY());
		}
	}
	if(check=="right")
	{
		lazyseg[0].setX(magicseg.getX()-10);
		lazyseg[0].setY(magicseg.getY());
	}
	if(check=="left")
	{
		lazyseg[0].setX(magicseg.getX()+10);
		lazyseg[0].setY(magicseg.getY());
	}
}
void Segment::avoidMuhsrooms(Position *MushroomPosition,int count)
{
	for(int a=0;a<count;a++)
	{
		if(magicseg.getX()>=MushroomPosition[a].getX()-10 && magicseg.getX()<=MushroomPosition[a].getX()+20 && magicseg.getY()>=MushroomPosition[a].getY()-5 && magicseg.getY()<=MushroomPosition[a].getY()+10)
		{
			if(check=="right")
			{
				check="left turn";
			}
			if(check=="left")
			{
				check="right turn";
			}
		}
	}
}
